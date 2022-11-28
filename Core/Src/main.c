/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file
 *      : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
// ====================

// ====================
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
// ====================

// ====================
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// ====================

// ====================
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
// ====================

// ====================
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
// ====================
const uint8_t SOCKET_NUM = 1;
int16_t socketStatus = -1;

// ====================
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
// ====================
void Wiznet_Init(void);
void Wiznet_Select(void);
void Wiznet_Unselect(void);
void Wiznet_ReadBuff(uint8_t* buff, uint16_t len);
void Wiznet_WriteBuff(uint8_t* buff, uint16_t len);
uint8_t Wiznet_ReadByte(void);
void Wiznet_WriteByte(uint8_t byte);
//void Wiznet_CrisExit_Callback(void);
//void Wiznet_CrisEnter_Callback(void);
// ====================
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// ====================

// ====================
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  // ====================

  // ====================
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  // ====================

  // ====================
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  // ====================

  // ====================
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_SPI2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  // ====================
  Wiznet_Init();

  // Timers
  __HAL_TIM_CLEAR_FLAG(&htim1, TIM_SR_UIF);
  HAL_TIM_Base_Start_IT(&htim1);
  //  __HAL_TIM_CLEAR_FLAG(&htim3, TIM_SR_UIF);
  //  HAL_TIM_Base_Start_IT(&htim3);
  // ~Timers

  // ====================
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  // ====================

  while (1)
  {
    // CLIENT
    printf("Opening a socket #%d\r\n", SOCKET_NUM);
    socketStatus = socket(SOCKET_NUM, Sn_MR_TCP, 818, Sn_MR_ND);
    if (socketStatus != SOCKET_NUM) {
      printf("Opening of a socket #%d, failed with code: %d\r\n",
             SOCKET_NUM, socketStatus);
  //      continue;
    } else {
      printf("Socket #%d successfully opened!\r\n",
             SOCKET_NUM);
    }
    HAL_Delay(1000);


    socketStatus = httpc_connect(SOCKET_NUM);
    if (SOCK_OK != socketStatus) {
      printf("Cannot connect to the server. Code: %d\r\n",
             socketStatus);
    } else {
      printf("Connected to: %d.%d.%d.%d:%d\r\n",
             SERVER_IP[0], SERVER_IP[1], SERVER_IP[2], SERVER_IP[3], SERVER_PORT);
    }
    HAL_Delay(1000);


    Request request = {
        GET,
        (uint8_t*)"/?page=getcmd&id=6&val=0&st=0",
        (uint8_t*)"192.168.1.23:80"
    };
    socketStatus = httpc_send(SOCKET_NUM, &request);
    if (socketStatus <= 0) {
      printf("send() failed. Code: %d\r\n", socketStatus);
    } else {
      printf("Request successfully sent. Len: %d\r\n", socketStatus);
    }
    HAL_Delay(1000);

    socketStatus = httpc_recv(SOCKET_NUM);
    if (socketStatus <= 0) {
      printf("recv() failed. Code: %d\r\n", socketStatus);
    } else {
      printf("Reply processed.\r\n");
    }
    HAL_Delay(1000);

    printf("Disconnecting socket #%d\r\n", SOCKET_NUM);
    disconnect(SOCKET_NUM);

    printf("Closing socket #%d\r\n", SOCKET_NUM);
    close(SOCKET_NUM);

    HAL_Delay(1000);

//     SERVER
//    printf("Opening a socket #%d\r\n", SOCKET_NUM);
//    socketStatus = socket(SOCKET_NUM, Sn_MR_TCP, 80, 0);
//    if (socketStatus != SOCKET_NUM) {
//      printf("Opening of socket #%d, failed with code: %d\r\n", SOCKET_NUM, socketStatus);
//  //      continue;
//    }
//    printf("Socket #%d successfully opened!\r\n", SOCKET_NUM);
//
//    socketStatus = listen(SOCKET_NUM);
//    if (socketStatus !=  SOCK_OK) {
//      printf("Can't listen a socket. Code: %d\r\n", socketStatus);
////      continue;
//    }
//    printf("Listing to socket #%d\r\n", SOCKET_NUM);
//
//    while (getSn_SR(SOCKET_NUM) == SOCK_LISTEN);
//
//    printf("Input connection\r\n");
//    if (getSn_SR(SOCKET_NUM) != SOCK_ESTABLISHED) {
//      printf("Socket listing error: %d\r\n", socketStatus);
//    }
//
//    uint8_t rIP[4];
//    getsockopt(SOCKET_NUM, SO_DESTIP, rIP);
//    printf("Listening to: %d.%d.%d.%d\r\n", rIP[0], rIP[1], rIP[2], rIP[3]);
//
//    sprintf(message, "Input counter = %d", iterator);
//
//    socketStatus = send(SOCKET_NUM, (uint8_t*)message, strlen(message));
//    if (socketStatus != strlen(message)) {
//      printf("Cannot send data! Code:%d\r\n", socketStatus);
//    }
//
//    disconnect(SOCKET_NUM);
//
////    printf("Closing socket\r\n");
////    close(SOCKET_NUM);
//
//    HAL_Delay(1000);
//    ++iterator;
//
//     ~SERVER

    // ====================
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    // ====================
//    HAL_Delay(1000);
  }
  // ====================
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */
  // ====================

  // ====================
  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */
  // ====================

  // ====================
  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 47999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */
  // ====================

  // ====================
  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 47999;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */
  // ====================

  // ====================
  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */
  // ====================

  // ====================
  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
  // ====================

  // ====================
  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|SPI2_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : UserBtn_Pin */
  GPIO_InitStruct.Pin = UserBtn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(UserBtn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI2_CS_Pin */
  GPIO_InitStruct.Pin = SPI2_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(SPI2_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED2_Pin */
  GPIO_InitStruct.Pin = LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI2_INT_Pin */
  GPIO_InitStruct.Pin = SPI2_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SPI2_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI2_RST_Pin */
  GPIO_InitStruct.Pin = SPI2_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(SPI2_RST_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 4 */
// ====================
// �?нициализация настроек устройства
void Wiznet_Init(void)
{
  // hard reset
  HAL_GPIO_WritePin(SPI2_RST_GPIO_Port, SPI2_RST_Pin, GPIO_PIN_RESET);
  HAL_Delay(70);
  HAL_GPIO_WritePin(SPI2_RST_GPIO_Port, SPI2_RST_Pin, GPIO_PIN_SET);
  HAL_Delay(70);

  // регистрация функций
  reg_wizchip_cs_cbfunc(Wiznet_Select, Wiznet_Unselect);
  reg_wizchip_spi_cbfunc(Wiznet_ReadByte, Wiznet_WriteByte);
  reg_wizchip_spiburst_cbfunc(Wiznet_ReadBuff, Wiznet_WriteBuff);
  //  reg_wizchip_cris_cbfunc(Wiznet_CrisEnter_Callback, Wiznet_CrisExit_Callback);

  // инициализация размеров буферов для сокетов
  uint8_t rx_tx_buff_sizes[2][8] = {
      { 2, 2, 2, 2, 2, 2, 2, 2, }, { 2, 2, 2, 2, 2, 2, 2, 2, }
  };
  ctlwizchip(CW_INIT_WIZCHIP, rx_tx_buff_sizes);

  // инициализация параметров сети
  wiz_NetInfo netInfo = {
      .mac  = { 0xD4, 0x3D, 0x7E, 0x50, 0xAB, 0x0F },
      .ip   = { 192, 168, 1, 123 },
      .sn   = { 255, 255, 255, 0 },
      .gw   = { 192, 168, 1, 23 },
//      .dns  = { 192, 168, 1, 1 },
      .dhcp = NETINFO_STATIC
  };
  ctlnetwork(CN_SET_NETINFO, (void*)&netInfo);
  printNetworkInfo();
}
void Wiznet_Select(void)
{
  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
//  printf("Wiznet_Select(void)\r\n");
}
void Wiznet_Unselect(void)
{
  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
//  printf("Wiznet_Unselect(void)\r\n");
}
void Wiznet_ReadBuff(uint8_t* buff, uint16_t len)
{
  HAL_SPI_Receive(&hspi2, buff, len, HAL_MAX_DELAY);
//  printf("Wiznet_ReadBuff(uint8_t* buff = %d, uint16_t len = %d)\r\n", *buff, len);
}
void Wiznet_WriteBuff(uint8_t* buff, uint16_t len)
{
//  printf("Wiznet_WriteBuff(uint8_t* buff = %d, uint16_t len = %d)\r\n", *buff, len);
  HAL_SPI_Transmit(&hspi2, buff, len, HAL_MAX_DELAY);
}
uint8_t Wiznet_ReadByte(void)
{
  uint8_t byte;
  Wiznet_ReadBuff(&byte, sizeof(byte));
//  printf("Wiznet_ReadByte(void)  byte = %d\r\n", byte);
  return byte;
}
void Wiznet_WriteByte(uint8_t byte)
{
//  printf("Wiznet_WriteByte(uint8_t byte = %d)\r\n", byte);
  Wiznet_WriteBuff(&byte, sizeof(byte));
}

//void Wiznet_CrisEnter_Callback(void)
//{
//  printf("Wiznet_CrisEnter_Callback\r\n");
//}

//void Wiznet_CrisExit_Callback(void)
//{
//  printf("Wiznet_CrisExit_Callback\r\n");
//}

// перенаправление printf в Uart
int _write(int file, char *ptr, int len)
{
  HAL_UART_Transmit(&huart1, (uint8_t*)ptr, len, HAL_MAX_DELAY);
  return len;
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  printf("EXTI_pin = %d\r\n", GPIO_Pin);
  if (GPIO_Pin == UserBtn_Pin) {
    HAL_GPIO_TogglePin(SPI2_RST_GPIO_Port, SPI2_RST_Pin);
//    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
  } else if (GPIO_Pin == SPI2_INT_Pin) {
    printf("Got LAN module's interrupt\r\n");
  }

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM1) {
    static uint32_t seconds = 0;
    ++seconds;
//    printf("%02d:%02d:%02d\r\n",
//           seconds / 60 / 60,
//           seconds / 60,
//           seconds % 60
//           );
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
  } else if (htim->Instance) {

  }
}

// ====================
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  // ====================
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
    HAL_Delay(200);
  }
  // ====================
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
  // ====================
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  // ====================
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
