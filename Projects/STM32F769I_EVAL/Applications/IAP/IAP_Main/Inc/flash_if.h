/**
  ******************************************************************************
  * @file    IAP/IAP_Main/Inc/flash_if.h 
  * @author  MCD Application Team
  * @brief   This file provides all the headers of the flash_if functions.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FLASH_IF_H
#define __FLASH_IF_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Base address of the Flash sectors */
#ifdef USE_DUAL_BANK_FLASH
  #define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbyte */
  #define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_12    ((uint32_t)0x08100000) /* Base @ of Sector 12, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_13    ((uint32_t)0x08104000) /* Base @ of Sector 13, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_14    ((uint32_t)0x08108000) /* Base @ of Sector 14, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_15    ((uint32_t)0x0810C000) /* Base @ of Sector 15, 16 Kbyte */
  #define ADDR_FLASH_SECTOR_16    ((uint32_t)0x08110000) /* Base @ of Sector 16, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_17    ((uint32_t)0x08120000) /* Base @ of Sector 17, 64 Kbyte */
  #define ADDR_FLASH_SECTOR_18    ((uint32_t)0x08140000) /* Base @ of Sector 18, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_19    ((uint32_t)0x08160000) /* Base @ of Sector 19, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_20    ((uint32_t)0x08180000) /* Base @ of Sector 20, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_21    ((uint32_t)0x081A0000) /* Base @ of Sector 21, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_22    ((uint32_t)0x081C0000) /* Base @ of Sector 22, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_23    ((uint32_t)0x081E0000) /* Base @ of Sector 23, 128 Kbyte */
#else  /* Use a Single Bank Flash */
  #define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 32 Kbyte */
  #define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08008000) /* Base @ of Sector 1, 32 Kbyte */
  #define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08010000) /* Base @ of Sector 2, 32 Kbyte */
  #define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08018000) /* Base @ of Sector 3, 32 Kbyte */
  #define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08020000) /* Base @ of Sector 4, 128 Kbyte */
  #define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08040000) /* Base @ of Sector 5, 256 Kbyte */
  #define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08080000) /* Base @ of Sector 6, 256 Kbyte */
  #define ADDR_FLASH_SECTOR_7     ((uint32_t)0x080C0000) /* Base @ of Sector 7, 256 Kbyte */
  #define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08100000) /* Base @ of Sector 8, 256 Kbyte */
  #define ADDR_FLASH_SECTOR_9     ((uint32_t)0x08140000) /* Base @ of Sector 9, 256 Kbyte */
  #define ADDR_FLASH_SECTOR_10    ((uint32_t)0x08180000) /* Base @ of Sector 10, 256 Kbyte */
  #define ADDR_FLASH_SECTOR_11    ((uint32_t)0x08C00000) /* Base @ of Sector 11, 256 Kbyte */
#endif /* #define USE_DUAL_BANK_FLASH */

/* Error code */
enum 
{
  FLASHIF_OK = 0,
  FLASHIF_ERASEKO,
  FLASHIF_WRITINGCTRL_ERROR,
  FLASHIF_WRITING_ERROR
};
  
enum{
  FLASHIF_PROTECTION_NONE         = 0,
  FLASHIF_PROTECTION_PCROPENABLED = 0x1,
  FLASHIF_PROTECTION_WRPENABLED   = 0x2,
  FLASHIF_PROTECTION_RDPENABLED   = 0x4,
};

#ifdef USE_DUAL_BANK_FLASH
  /* End of the Flash address */
  #define USER_FLASH_END_ADDRESS     (uint32_t)0x08107FFF
  /* Define the user application size */
  #define USER_FLASH_SIZE   (USER_FLASH_END_ADDRESS - APPLICATION_ADDRESS + 1)

  /* Define the address from where user application will be loaded.
     Note: the 1st sector 0x08000000-0x08003FFF is reserved for the IAP code */
  #define APPLICATION_ADDRESS        (uint32_t)0x08100000

  /* Define bitmap representing user flash area that could be write protected (check restricted to pages 8-39). */
  #define FLASH_SECTOR_TO_BE_PROTECTED (OB_WRP_DB_SECTOR_0 | OB_WRP_DB_SECTOR_1 | OB_WRP_DB_SECTOR_2 | OB_WRP_DB_SECTOR_3 |\
                                      OB_WRP_DB_SECTOR_4 | OB_WRP_DB_SECTOR_5 | OB_WRP_DB_SECTOR_6 | OB_WRP_DB_SECTOR_7 |\
                                      OB_WRP_DB_SECTOR_8 | OB_WRP_DB_SECTOR_9 | OB_WRP_DB_SECTOR_10 | OB_WRP_DB_SECTOR_11 |\
                                      OB_WRP_DB_SECTOR_12 | OB_WRP_DB_SECTOR_13 | OB_WRP_DB_SECTOR_14 | OB_WRP_DB_SECTOR_15 |\
                                      OB_WRP_DB_SECTOR_16 | OB_WRP_DB_SECTOR_17 | OB_WRP_DB_SECTOR_18 | OB_WRP_DB_SECTOR_19 |\
                                      OB_WRP_DB_SECTOR_20 | OB_WRP_DB_SECTOR_21 | OB_WRP_DB_SECTOR_22 | OB_WRP_DB_SECTOR_23 )
#else  /* Use a Single Bank Flash */
  /* End of the Flash address */
  #define USER_FLASH_END_ADDRESS      (uint32_t)0x0800FFFF
  /* Define the user application size */
  #define USER_FLASH_SIZE   (USER_FLASH_END_ADDRESS - APPLICATION_ADDRESS + 1)

  /* Define the address from where user application will be loaded.
     Note: the 1st sector 0x08000000-0x08003FFF is reserved for the IAP code */
  #define APPLICATION_ADDRESS        (uint32_t)0x08008000

  /* Define bitmap representing user flash area that could be write protected (check restricted to pages 8-39). */
  #define FLASH_SECTOR_TO_BE_PROTECTED (OB_WRP_SECTOR_0 | OB_WRP_SECTOR_1 | OB_WRP_SECTOR_2 | OB_WRP_SECTOR_3 |\
                                      OB_WRP_SECTOR_4 | OB_WRP_SECTOR_5 | OB_WRP_SECTOR_6 | OB_WRP_SECTOR_7 |\
                                      OB_WRP_SECTOR_8 | OB_WRP_SECTOR_9 | OB_WRP_SECTOR_10 | OB_WRP_SECTOR_11)
#endif /* #define USE_DUAL_BANK_FLASH */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void              FLASH_If_Init(void);
uint32_t          FLASH_If_Erase(uint32_t StartSector);
uint32_t          FLASH_If_Write(uint32_t FlashAddress, uint32_t* Data, uint32_t DataLength);
uint16_t          FLASH_If_GetWriteProtectionStatus(void);
HAL_StatusTypeDef FLASH_If_WriteProtectionConfig(uint32_t modifier);

#endif  /* __FLASH_IF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
