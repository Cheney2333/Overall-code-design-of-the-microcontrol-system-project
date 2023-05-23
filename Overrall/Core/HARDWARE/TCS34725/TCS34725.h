#ifndef __TCS34725_H__
#define __TCS34725_H__

#include "main.h" //HAL库文件声明

#define TCS34725_ENABLE_PON 0x01     // PON ENABLE
#define TCS34725_ENABLE_AEN 0x02     // AEN ENAGLE
#define TCS34725__STATUS_AVALID 0x01 // RGBC avalid
#define TCS34725_CMD_MASK 0x80       // Command Register

#define I2C_TCS34725_ADDR 0x29 // TCS34725's address

#define TCS34725_ENABLE_ADDR 0x00 // Enable register's address
#define TCS34725_ID_ADDR 0x12     // ID register's address
#define TCS34725_STATUS_ADDR 0x13 // Status register's address
#define TCS34725_CDATA_ADDR 0x14  // Clear data low byte
#define TCS34725_CDATAH_ADDR 0x15 // Clear data high byte
#define TCS34725_RDATA_ADDR 0x16  // Red data low byte
#define TCS34725_RDATAH_ADDR 0x17 // Red data high byte
#define TCS34725_GDATA_ADDR 0x18  // Green data low byte
#define TCS34725_GDATAH_ADDR 0x19 // Green data high byte
#define TCS34725_BDATA_ADDR 0x1A  // Blue data low byte
#define TCS34725_BDATAH_ADDR 0x1B // Blue data high byte

static void TCS34725_ENABLE(void);
static uint16_t TCS34725_Get_RawData(I2C_HandleTypeDef *hi2c, uint16_t MemAddress);
static void Send_RAWData_To_UART(char RGBC, uint16_t RawData);

#endif