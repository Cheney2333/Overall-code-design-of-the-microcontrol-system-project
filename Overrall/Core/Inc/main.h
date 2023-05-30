/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
typedef struct{
	unsigned short  c;      //[0-65536]
	unsigned short  r;
	unsigned short  g;
	unsigned short  b;
}COLOR_RGBC;//RGBC
 
typedef struct{
	unsigned short h;       //[0,360]
	unsigned char  s;       //[0,100]
	unsigned char  l;       //[0,100]
}COLOR_HSL;//HSL
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TCS_SCL_Pin GPIO_PIN_0
#define TCS_SCL_GPIO_Port GPIOC
#define TCS_SDA_Pin GPIO_PIN_3
#define TCS_SDA_GPIO_Port GPIOC
#define Beep_Pin GPIO_PIN_4
#define Beep_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Servo1_Pin GPIO_PIN_4
#define Servo1_GPIO_Port GPIOB
#define Servo2_Pin GPIO_PIN_5
#define Servo2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define I2C_READ 0x01
#define RX_BUFFER_SIZE 256
#define RXBUFFERSIZE  256 // 定义接收字符串的�?大长�?
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
