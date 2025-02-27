/**
  ******************************************************************************
  * @file    CRYP/CRYP_TDESmodes/Src/main.c
  * @author  MCD Application Team
  * @brief   This sample code shows how to use the STM32F7xx CRYP HAL API
  *          to encrypt and decrypt data using TDES in ECB and CBC Algorithm.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup CRYP_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* CRYP handler declaration */
static CRYP_HandleTypeDef hcryp;
static CRYP_ConfigTypeDef Conf;

/* Triple Key  */
uint32_t TDESKey[6] = { 0x01234567,0x89ABCDEF, 
                        0x23456789,0xABCDEF01, 
                        0x456789AB,0xCDEF0123};

/*Initialization Vector*/ 
uint32_t InitVector[2] = {0xF69F2445 ,0xDF4F9B17};
  
/* Plaintext */
uint32_t Plaintext[8] = { 0x6BC1BEE2, 0x2E409F96, 0xE93D7E11, 0x7393172A,
                          0xAE2D8A57, 0x1E03AC9C, 0x9EB76FAC, 0x45AF8E51};

/* Expected ECB Ciphertext */
uint32_t Ciphertext_ECB[8] = {0x714772F3, 0x39841D34,0x267FCC4B,0xD2949CC3,
                              0xEE11C22A, 0x576A3038, 0x76183F99, 0xC0B6DE87};

/* Expected CBC Ciphertext */
uint32_t Ciphertext_CBC[8] = {0x2079C3D5, 0x3AA763E1, 0x93B79E25 , 0x69AB5262,
                              0x51657048, 0x1F25B50F , 0x73C0BDA8 , 0x5C8E0DA7}; 

/* Used for storing Encrypted text */
uint32_t Encryptedtext[8]={0}; 

/* Used for storing Decrypted text */
uint32_t Decryptedtext[8]={0}; 

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void CPU_CACHE_Enable(void);
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the system clock to 216 MHz */
  SystemClock_Config();

  /* Configure LED1 and LED3 */
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED3);
   
  /*## Set the CRYP parameters and initialize the IP  ######################################*/ 
  hcryp.Instance      = CRYP;
  hcryp.Init.DataType = CRYP_DATATYPE_32B;
  hcryp.Init.pKey     = TDESKey;
  hcryp.Init.Algorithm = CRYP_TDES_ECB;
  HAL_CRYP_Init(&hcryp);
  
  /*##-1- TDES ECB Encryption  #######################################*/ 

  /* Encryption, result in  Encryptedtext buffer */ 
  HAL_CRYP_Encrypt(&hcryp, Plaintext, 8, Encryptedtext, TIMEOUT_VALUE);
  if(memcmp(Encryptedtext, Ciphertext_ECB, 32) != 0)
  {
    /* Not expected result, wrong on Encryptedtext buffer: Turn LED3 on */
    Error_Handler();
  }
  /*##-2- TDES CBC Encryption  #######################################*/   

  /* Get current CRYP parameters */  
   HAL_CRYP_GetConfig(&hcryp, &Conf); 
  
  /* Set new parameters and configure the CRYP */
  Conf.pInitVect = InitVector;  
  Conf.Algorithm = CRYP_TDES_CBC;
  HAL_CRYP_SetConfig(&hcryp, &Conf);
  
  /* Encryption, result in  Encryptedtext buffer */ 
  HAL_CRYP_Encrypt(&hcryp, Plaintext, 8, Encryptedtext, TIMEOUT_VALUE);
  
  if(memcmp(Encryptedtext, Ciphertext_CBC, 32) != 0)
  {   /* Not expected result, wrong on Encryptedtext buffer: Turn LED3 on */
    Error_Handler();
  }
  /*##-3- TDES ECB Decryption  #######################################*/ 

  /* Set new parameters and configure the CRYP */
  Conf.Algorithm = CRYP_TDES_ECB;
  HAL_CRYP_SetConfig(&hcryp, &Conf);
  
  /* Decryption, result in  Decryptedtext buffer */ 
  HAL_CRYP_Decrypt(&hcryp, Ciphertext_ECB , 8, Decryptedtext, TIMEOUT_VALUE);
  if(memcmp(Decryptedtext, Plaintext, 32) != 0)
  {
    /* Not expected result, wrong on Decryptedtext buffer: Turn LED3 on */
    Error_Handler();
  }
  /*##-4- TDES CBC Decryption  #######################################*/   
  
  /* Set new parameters and configure the CRYP */
  Conf.Algorithm = CRYP_TDES_CBC;
  HAL_CRYP_SetConfig(&hcryp, &Conf); 
  
  /* Decryption, result in  Decryptedtext buffer */ 
  HAL_CRYP_Decrypt(&hcryp, Ciphertext_CBC, 8, Decryptedtext, TIMEOUT_VALUE);
  
  if(memcmp(Decryptedtext, Plaintext, 32) != 0)
  {   /* Not expected result, wrong on Decryptedtext buffer: Turn LED3 on */
    Error_Handler();
  }  
  else
  {
    /* Right Encryptedtext & Decryptedtext buffer : Turn LED1 on */
    BSP_LED_On(LED1);
  }

  /* Infinite loop */
  while (1)
  {
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
  
  /* Activate the OverDrive to reach the 216 MHz Frequency */  
  ret = HAL_PWREx_EnableOverDrive();
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2; 
  
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }  
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* Turn LED3 on */
  BSP_LED_On(LED3);
  while (1)
  {
  }  

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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
