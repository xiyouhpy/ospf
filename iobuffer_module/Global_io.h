// =====================================================================================
//
//       Filename:  Global_io.h
//
//    Description:  系统调用全局变量
//
// =====================================================================================
#ifndef GLOBAL_IO_H_
#define GLOBAL_IO_H_

// 缓冲区大小
#define BUFFSIZE 1024

#include <stdint.h>

typedef struct {

	// 输入缓冲区
	uint8_t Inputbuffer[BUFFSIZE];

	// 当前输入缓冲区大小
	uint32_t InputSize;

	// 输入标志位（1，表示已经输入了数据 0，表示空闲状态）
	uint32_t Inputleap;

	// 输入终端标志位（表示是哪个终端进行输入的）
	uint32_t Inputnum;

	// 进程标志位（标志是哪个进程的输入 IO 支持）
	uint32_t Inputpid;

} i_operate;
	
	
typedef struct {

	// 输出缓冲区
	uint8_t Outputbuffer[BUFFSIZE];

	// 当前输出缓冲区大小
	uint32_t OutputSize;

	// 输出标志位（1，表示已经输出了数据 0，表示空闲状态）
	uint32_t Outputleap;

	// 输出终端标志位（表示是哪个终端进行输入的）
	uint32_t Outputnum;

	// 进程标志位（标志是哪个进程的输出 IO 支持）
	uint32_t Outputpid;

} o_operate;


#endif  // GLOBAL_IO_H_
