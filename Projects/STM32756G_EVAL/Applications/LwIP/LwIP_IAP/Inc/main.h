/**
  ******************************************************************************
  * @file    LwIP/LwIP_IAP/Inc/main.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the main.c 
  *          file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32756g_eval.h"
#include "stm32756g_eval_lcd.h"
#include "stm32756g_eval_io.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* IAP options selection ******************************************************/
#define USE_IAP_TFTP   /* enable IAP using TFTP */
#define USE_IAP_HTTP   /* enable IAP using HTTP */
#define USE_LCD        /* enable LCD  */  
#define USE_DHCP       /* enable DHCP, if disabled static address is used */

/* Flash user area definition *************************************************/   
/* 
   IMPORTANT NOTE:
   ==============
   Be sure that USER_FLASH_FIRST_PAGE_ADDRESS do not overlap with IAP code.
   For example, with all option enabled the total readonly memory size using
   gcc compiler, is 76676 bytes.
   Based on this result four sectors of 16 Kbytes and a sector of 64 Kbytes will 
   be used to store the IAP code, so the user Flash address will start from Sector5.

   In this application the define USER_FLASH_FIRST_PAGE_ADDRESS is set to 128K boundary,
   but it can be changed to any other address outside the 1st 128 Kbytes of the Flash.
   */
#define USER_FLASH_FIRST_PAGE_ADDRESS 0x08020000 /* Only as example see comment */
#define USER_FLASH_LAST_PAGE_ADDRESS  0x080C0000
#define USER_FLASH_END_ADDRESS        0x080FFFFF  
   
/* UserID and Password definition *********************************************/
#define USERID       "user"
#define PASSWORD     "stm32"
#define LOGIN_SIZE   (17+ sizeof(USERID) + sizeof(PASSWORD))
 
/* Static IP Address definition ***********************************************/
#define IP_ADDR0   192
#define IP_ADDR1   168
#define IP_ADDR2   0
#define IP_ADDR3   10

/* NETMASK definition *********************************************************/
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/* Gateway Address definition *************************************************/
#define GW_ADDR0   192
#define GW_ADDR1   168
#define GW_ADDR2   0
#define GW_ADDR3   1

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */  
/* Exported function prototypes ----------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
