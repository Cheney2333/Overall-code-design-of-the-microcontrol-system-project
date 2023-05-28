#ifndef __Vl6180_H__
#define __Vl6180_H__

#include "main.h" //HAL库文件声明

#define VL6180X_DEFAULT_ID 0xB4
#define VL6180X_DEFAULT_I2C_ADDR 0x29
#define VL6180X_REG_ID 0x000

#define VL6180X_REG_SYSTERM_INTERRUPT_CLEAR 0x15
#define VL6180X_REG_SYSRANGE_START 0x018 // 2byte address
#define VL6180X_REG_RESULT_RANGE_STATUS 0x04D
#define VL6180X_REG_RESULT_INTERRUPT_STATUS 0x04F
#define VL6180X_REG_RESULT_RANGE_VAL 0x062

#define VL6180X_REG_ADDRESS_SIZE 2

#define VL6180X_ERROR_NONE 0        // no error
#define VL6180X_ERROR_SYSERR_1 1    // system error 1
#define VL6180X_ERROR_SYSERR_5 5    // system error 5
#define VL6180X_ERROR_ECEFAIL 6     // early convergence estimate fail
#define VL6180X_ERROR_NOCONVERGE 7  // no target detected
#define VL6180X_ERROR_RANGEIGNORE 8 // ignore threshold check failed
#define VL6180X_ERROR_SNR 11        // ambient condition too high
#define VL6180X_ERROR_RAWFLOW 12    // raw range algo underflow
#define VL6180X_ERROR_RAEUFLOW 13   // raw range algo overflow
#define VL6180X_ERROR_RANGEFLOW 14  // ranging algo underflow
#define VL6180X_ERROR_RANGEUFLOW 15 // ranging algo overflow

void VL6180X_Init(void);
// write one byte to VL6180X
HAL_StatusTypeDef VL6180X_WriteByte(uint16_t regAddress, uint8_t data);
// read one byte from VL6180X
HAL_StatusTypeDef VL6180X_ReadByte(uint16_t regAddress, uint8_t *data);
// get id of VL6180X
uint8_t VL6180X_GetID(void);
// get the range from VL6180X
uint8_t VL6180X_GetRange(void);

#endif
