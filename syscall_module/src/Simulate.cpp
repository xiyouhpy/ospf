// =====================================================================================
//
//       Filename:  Simulate.cpp
//
//    Description:  字节码解释器
//
// =====================================================================================

#include <stdint.h>
#include <iostream>

#include "CurrentThread.h"
#include "Simulate.h"
#include "Syscalls.h"

namespace ospf {

namespace simulate {

// 函数指针
typedef int32_t (*sim_func_t)(uint8_t *, uint8_t *);

static int32_t sim_add(uint8_t *byte_code, uint8_t *byte_data);

static int32_t sim_sub(uint8_t *byte_code, uint8_t *byte_data);

static int32_t sim_syscall(uint8_t *byte_code, uint8_t *byte_data);

// 具体字节码处理函数（函数指针数组）
static sim_func_t sim_func[BYTE_CODE_MAX + 1] = {
        NULL,
        &sim_add,
        &sim_sub,
        &sim_syscall
};

bool simulate(uint8_t *byte_code, uint32_t code_len, uint8_t *byte_data, uint32_t data_len)
{
        for (uint32_t i = 0; i < code_len; ++i) {
        	if (CurrentThread::is_intr) {
        		if (CurrentThread::intr_no != 0) {
        			// TODO 中断处理
        		}
        	}
                if (byte_code[i] <= 0 || byte_code[i] > BYTE_CODE_MAX) {
                        // errno = XXXX （错误处理）
                        return false;
                }
                
                sim_func[byte_code[0]](byte_code, byte_data);
        }
        
        return true;
}

// 字节码加法实现
static int32_t sim_add(uint8_t *byte_code, uint8_t *byte_data)
{
        return 0;
}

// 字节码减法实现
static int32_t sim_sub(uint8_t *byte_code, uint8_t *byte_data)
{
        return 0;
}

// 字节码系统调用过程转换实现
static int32_t sim_syscall(uint8_t *byte_code, uint8_t *byte_data)
{
	uint32_t *word_data = (uint32_t *)byte_data;
        uint32_t sysno = *word_data++;
        int32_t nr_args = syscall::get_syscall_nr_args(sysno);
        uint32_t nr_data = 1;
        
        if (nr_args == -1) {
		printf("系统调用参数错误!\n");
                return false;
		// ........
        }
        
	if (nr_args > 0) {
        	if (sysno == SYS_EXIT) {                                                    // exit
			uint32_t num;

        		num = *word_data++;

                	uint32_t count = (sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	nr_data += count;

			uint32_t *args = new uint32_t[nr_args];
			args[0] = num;
                	
			ospf::syscall::syscall(sysno, args);
			
			delete []args;

		}else if (sysno == SYS_OPEN) {                                              // open
			uint32_t flag;
			uint8_t *buffer = NULL;
			uint32_t len;
        		
			len = *word_data++;
			flag = *word_data++;
                	buffer = new uint8_t[len];
                
                	uint32_t count = (len + sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	uint32_t *pbuff = (uint32_t *)buffer;
                	for (uint32_t i = 0; i < count; ++i) {
                		pbuff[i] = *word_data++;
                	}
                	
                	nr_data += count;
                	
			uint32_t *args = new uint32_t[nr_args];
			args[0] = (uint32_t)buffer;
			args[1] = flag;
                                
			ospf::syscall::syscall(sysno, args);
			if (buffer) {
				delete []buffer;
			        buffer = NULL;
			}
			delete []args;

        	} else if (sysno == SYS_CLOSE) {                                            // close
			uint32_t fileno;

        		fileno = *word_data++;

                	uint32_t count = (sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	nr_data += count;

			uint32_t *args = new uint32_t[nr_args];
			args[0] = fileno;
                	
			ospf::syscall::syscall(sysno, args);
			
			delete []args;

        	} else if (sysno == SYS_WRITE) {                                            // write
			uint32_t fileno;
			uint8_t *buffer = NULL;
			uint32_t len;

        		fileno = *word_data++;
        		len = *word_data++;
                	buffer = new uint8_t[len];
                
                	uint32_t count = (len + sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	uint32_t *pbuff = (uint32_t *)buffer;
                	for (uint32_t i = 0; i < count; ++i) {
                		pbuff[i] = *word_data++;
                	}
                	
                	nr_data += count;
			
			uint32_t *args = new uint32_t[nr_args];
			args[0] = fileno;
			args[1] = (uint32_t)buffer;
			args[2] = len;        
                	
			ospf::syscall::syscall(sysno, args);
			if (buffer) {
				delete []buffer;
			        buffer = NULL;
			}
			delete []args;

        	} else if (sysno == SYS_READ) {                                             // read
			uint32_t fileno;
			uint8_t *buffer = NULL;
			uint32_t len;
        		
			fileno = *word_data++;
        		len = *word_data++;
                	buffer = new uint8_t[len];
                
                	uint32_t count = (len + sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	uint32_t *pbuff = (uint32_t *)buffer;
                	for (uint32_t i = 0; i < count; ++i) {
                		pbuff[i] = *word_data++;
                	}
                	
                	nr_data += count;
                	
			uint32_t *args = new uint32_t[nr_args];
			args[0] = fileno;
			args[1] = (uint32_t)buffer;
			args[2] = len;
                                
			ospf::syscall::syscall(sysno, args);
			if (buffer) {
				delete []buffer;
				buffer = NULL;
			}
			delete []args;

		} else if (sysno == SYS_KILL) {                                             // kill
			uint32_t pid;
			uint32_t operate;

        		pid = *word_data++;
			operate = *word_data++;

                	uint32_t count = (sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	nr_data += count;

			uint32_t *args = new uint32_t[nr_args];
			args[0] = pid;
			args[1] = operate;
                	
			ospf::syscall::syscall(sysno, args);
			
			delete []args;

        	} else if (sysno == SYS_MALLOC) {                                           // malloc
			uint32_t size;

        		size = *word_data++;

                	uint32_t count = (sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	nr_data += count;

			uint32_t *args = new uint32_t[nr_args];
			args[0] = size;
                	
			ospf::syscall::syscall(sysno, args);
			
			delete []args;

        	} else if (sysno == SYS_FREE) {                                             // free
			uint8_t *buffer = NULL;
			uint32_t len;

        		len = *word_data++;
                	buffer = new uint8_t[len];
                
                	uint32_t count = (len + sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	uint32_t *pbuff = (uint32_t *)buffer;
                	for (uint32_t i = 0; i < count; ++i) {
                		pbuff[i] = *word_data++;
                	}
                	
                	nr_data += count;
			
			uint32_t *args = new uint32_t[nr_args];
			args[0] = (uint32_t)buffer;
			args[1] = len;        
                	
			ospf::syscall::syscall(sysno, args);
			if (buffer) {
				delete []buffer;
			        buffer = NULL;
			}
			delete []args;

        	} else if (sysno == SYS_CREAT) {                                            // creat
			uint32_t mode;
			uint8_t *buffer = NULL;
			uint32_t len;
        		
			len = *word_data++;
        		mode = *word_data++;
                	buffer = new uint8_t[len];
                
                	uint32_t count = (len + sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	uint32_t *pbuff = (uint32_t *)buffer;
                	for (uint32_t i = 0; i < count; ++i) {
                		pbuff[i] = *word_data++;
                	}
                	
                	nr_data += count;
  

			uint32_t *args = new uint32_t[nr_args];
			args[0] = (uint32_t)buffer;
			args[1] = mode;
                                
			ospf::syscall::syscall(sysno, args);
			if (buffer) {
				delete []buffer;
				buffer = NULL;
			}
			delete []args;

        	} else if (sysno == SYS_LSEEK) {                                            // lseek
			uint32_t handle;
			uint32_t offset;
			uint32_t fromwhere;
        		
			handle = *word_data++;
        		offset = *word_data++;
                	fromwhere = *word_data++;
                
                	uint32_t count = (sizeof(uint32_t)-1) / sizeof(uint32_t);	
                	
                	nr_data += count;
                	
			uint32_t *args = new uint32_t[nr_args];
			args[0] = handle;
			args[1] = offset;
			args[2] = fromwhere;
                                
			ospf::syscall::syscall(sysno, args);
			
			delete []args;

			//...
		}// TODO else
        	
        } else {
                syscall::syscall(sysno, NULL);
        }

        // nr_data + sysno
        return (nr_data + 1) * sizeof(uint32_t);
}

}       // namespace Simulate

}       // namespace ospf
