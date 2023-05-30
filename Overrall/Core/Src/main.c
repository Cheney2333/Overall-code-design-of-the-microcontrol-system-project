/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "TCS34725.h"
#include "Vl6180x.h"
#include "cJSON.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t distance = 0;
int count = 0;
COLOR_RGBC rgb;
COLOR_HSL hsl;
uint8_t g_ucUsart1ReceiveData;
uint8_t g_ucUsart6ReceiveData;
uint8_t cmd = 0;
uint8_t rxBuffer[RX_BUFFER_SIZE];
uint32_t rxBufferIndex = 0;

char RxBuffer[RXBUFFERSIZE]; // 接收数据
uint8_t aRxBuffer;           // 接收中断缓冲
uint8_t Uart1_Rx_Cnt = 0;    // 接收缓冲计数

int flag = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void L610_Init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  MX_TIM1_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_USART6_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_UART_Receive_IT(&huart1, &g_ucUsart1ReceiveData, 1);
  // HAL_UART_Receive_IT(&huart6, &g_ucUsart6ReceiveData, 1);
  HAL_UART_Receive_IT(&huart6, &g_ucUsart6ReceiveData, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  if (VL6180X_GetID() == VL6180X_DEFAULT_ID)
    VL6180X_Init();
  while (!TCS34725_Init())
  {
    printf("Color Sensor Init Error!\r\n");
  }
  while (1)
  {
    if (flag == 0)
    {
      HAL_Delay(20);
      L610_Init();
      flag = 1;
      HAL_GPIO_WritePin(Servo1_GPIO_Port, Servo1_Pin, 1); // LeftClose
      HAL_GPIO_WritePin(Servo2_GPIO_Port, Servo2_Pin, 1); // LeftClose
    }
    distance = VL6180X_GetRange();
    TCS34725_GetRawData(&rgb);
    printf("distance: %d mm; r: %d, g: %d, b: %d\r\n", distance, rgb.r, rgb.g, rgb.b);
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    HAL_Delay(1000);
    // HAL_UART_Receive_IT(&huart6, (uint8_t *)&cmd, 1);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim1) // htim1 50HZ 20ms
  {
  }
}
void L610_Init()
{
  HAL_UART_Transmit(&huart6, (uint8_t *)"AT+MIPCALL=1\r\n", sizeof("AT+MIPCALL=1\r\n\r\n"), 0xFFFF);
  HAL_Delay(10);
  HAL_UART_Transmit(&huart6, (uint8_t *)"AT+TCDEVINFOSET=1,\"7WB0TXD3D0\",\"servo_01\",\"tMamURuuJjVpBLXCdh13rw==\"\r\n", sizeof("AT+TCDEVINFOSET=1,\"7WB0TXD3D0\",\"servo_01\",\"tMamURuuJjVpBLXCdh13rw==\"\r\n"), 0xFFFF);
  HAL_Delay(10);
  HAL_UART_Transmit(&huart6, (uint8_t *)"AT+TCMQTTCONN=1,20000,240,1,1\r\n", sizeof("AT+TCMQTTCONN=1,20000,240,1,1\r\n"), 0xFFFF);
  HAL_Delay(10);
  HAL_UART_Transmit(&huart6, (uint8_t *)"AT+TCMQTTSUB=\"$thing/down/property/7WB0TXD3D0/servo_01\",1\r\n", sizeof("AT+TCMQTTSUB=\"$thing/down/property/7WB0TXD3D0/servo_01\",1\r\n"), 0xFFFF);
  HAL_Delay(10);
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
