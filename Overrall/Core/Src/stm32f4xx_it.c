/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f4xx_it.c
 * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "cJSON.h"
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern uint8_t g_ucUsart1ReceiveData;
extern uint8_t g_ucUsart6ReceiveData;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;
extern uint8_t bRxBuffer[RXBUFFERSIZE];
extern uint8_t rxBuffer[RX_BUFFER_SIZE];
extern uint16_t rxBufferIndex;
extern uint8_t rxData;
extern uint8_t cmd;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */

  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void ExtractJsonFromMQTT(char *mqttString, char *jsonString)
{
  char *start = strchr(mqttString, '{'); // ?????????
  char *end = strrchr(mqttString, '}');  // ??????????

  if (start != NULL && end != NULL && end > start)
  {
    int length = end - start + 1; // ??JSON??????

    // ??JSON????jsonString???
    strncpy(jsonString, start, length);

    // ????????
    jsonString[length] = '\0';
  }
  else
  {
    // ?????JSON?????jsonString???????
    jsonString[0] = '\0';
  }
}

void ProcessMQTTMessage(char *message)
{
  // Find the parameter values in the MQTT message
  const char *openRightStr = strstr(message, "\"openright\":");
  const char *openLeftStr = strstr(message, "\"openleft\":");

  // Extract the parameter values using cJSON library
  cJSON *root = cJSON_Parse(message);
  if (root != NULL)
  {
    if (openRightStr != NULL)
    {
      cJSON *openRightValue = cJSON_GetObjectItem(root, "openright");
      if (openRightValue != NULL && cJSON_IsNumber(openRightValue))
      {
        int openRight = openRightValue->valueint;
        // Do something with the "openright" value
        if (openRight == 0)
        {
          HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 1); // LeftClose
        }
        else if (openRight == 1)
        {
          HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 0); // LeftClose
        }
      }
    }

    if (openLeftStr != NULL)
    {
      cJSON *openLeftValue = cJSON_GetObjectItem(root, "openleft");
      if (openLeftValue != NULL && cJSON_IsNumber(openLeftValue))
      {
        int openLeft = openLeftValue->valueint;
        // Do something with the "openleft" value
        if (openLeft == 0)
        {
          HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 1); // LeftClose
        }
        else if (openLeft == 1)
        {
          HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 0); // LeftClose
        }
      }
    }

    cJSON_Delete(root);
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart == &huart1)
  {
    if (g_ucUsart1ReceiveData == '0')
      HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 1); // LeftClose
    if (g_ucUsart1ReceiveData == '1')
      HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 0); //
    if (g_ucUsart1ReceiveData == '2')
      HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 1); // RightClose
    if (g_ucUsart1ReceiveData == '3')
      HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 0);
    if (g_ucUsart1ReceiveData == '4')
    {
      HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 0); // Open
      HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 0);
    }
    if (g_ucUsart1ReceiveData == '5')
    {
      HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 1); // Close
      HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 1);
    }
    HAL_UART_Receive_IT(&huart1, &g_ucUsart1ReceiveData, 1);
  }

  if (huart == &huart6)
  {
    // Change GPIO level here
    // Replace GPIOX and GPIO_PIN_X with your actual GPIO port and pin
    HAL_GPIO_TogglePin(Servo1_GPIO_Port, Servo1_Pin);
    HAL_GPIO_TogglePin(Servo2_GPIO_Port, Servo2_Pin);

    // Start listening for next byte
    HAL_UART_Receive_IT(&huart6, &g_ucUsart6ReceiveData, 1);
  }
}
/* USER CODE END 1 */
