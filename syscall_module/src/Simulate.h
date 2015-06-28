// =====================================================================================
//
//       Filename:  Simulate.h
//
//    Description:  字节码解释器
//
// =====================================================================================

#ifndef SIMULATE_H_
#define SIMULATE_H_

// 字节码定义
enum byte_code_t {
        SIMU_ADD = 0x1,         // 加法字节码
        SIMU_SUB = 0x2,         // 减法字节码
        SIMU_SYSCALL = 0x3      // 系统调用字节码
};

// 最大系统调用数目宏
#define BYTE_CODE_MAX 0x3

namespace ospf {

namespace simulate {

// 系统调用对外接口函数
bool simulate(uint8_t *byte_code, uint32_t code_len, uint8_t *byte_data, uint32_t data_len);

}

}

#endif // SIMULATE_H_
