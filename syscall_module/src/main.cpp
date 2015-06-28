// =====================================================================================
//
//       Filename:  main.cpp
//
//    Description:  主函数入口
//
// =====================================================================================

#include <iostream>
#include <functional>
#include <stdlib.h>

#include "ThreadPool.h"
#include "Simulate.h"

using namespace ospf;

int main(int argc, char *argv[])
{
	printf("OSPF Running ...\n");
	
        ThreadPool threadPool("OSPF Runtime");

        threadPool.setMaxQueueSize(100);

        threadPool.start(10);

        // 哈佛结构（代码和数据分开）
	uint8_t byte_code[] = {0x3};                  // 字节码中系统调用位置号
	uint32_t code_len = sizeof(byte_code);        // 代码长度
	
	// test open
	uint8_t byte_data0[] = {0x1, 0x0, 0x0, 0x0,   // 4
	 			0x6, 0x0, 0x0, 0x0,
				0x2, 0x0, 0x0, 0x0,   // open 函数第二个参数
				'1', '.', 't', 'x', 't', '\0'};
	 			
	// test write
	uint8_t byte_data1[] = {0x4, 0x0, 0x0, 0x0,   // 4（第四个系统调用）
                            	 0x1, 0x0, 0x0, 0x0,  // 1（该系统调用第一个参数）
				 0xE, 0x0, 0x0, 0x0,  // 14（16进制的 0xE 就是 14）表示下面的参数字符串的长度为 14 个字节
	 			'H', 'e', 'l', 'l', 'o', ',', ' ', 'O', 'S', 'P', 'F', '0', '!', '\n'}; // 参数字符串

	uint32_t data_len0 = sizeof(byte_data0);       // 数据长度
	uint32_t data_len1 = sizeof(byte_data1);

        threadPool.run(std::bind(simulate::simulate, byte_code, code_len, byte_data0, data_len0));
        threadPool.run(std::bind(simulate::simulate, byte_code, code_len, byte_data1, data_len1));
        sleep(1);
        threadPool.stop();

        return 0;
}

