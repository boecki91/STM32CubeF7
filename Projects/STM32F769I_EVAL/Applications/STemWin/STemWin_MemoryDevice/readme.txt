/**
  @page STemWin_MemoryDevice  STemWin memory device Readme file
 
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    STemWin/STemWin_MemoryDevice/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of STemWin memory device application. 
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
   @endverbatim

@par Application Description

This directory contains a set of source files that implement a simple "memory device" 
application based on STemWin for STM32F7xx devices.

The application shows the capability of STemWin to use the memory devices to achieve tricky operations
like rotations, shifts and zoom. 

 How to interact with the application
 ------------------------------------
 - The application is an automatic run.
 - It will show an alternance between rotating, zooming, shifting of different wheels
 - It will loop infinetly.  

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@Note If the user code size exceeds the DTCM-RAM size or starts from internal cacheable memories (SRAM1 and SRAM2),that is shared between several processors,
      then it is highly recommended to enable the CPU cache and maintain its coherence at application level.
      The address and the size of cacheable buffers (shared between CPU and other masters)  must be properly updated to be aligned to cache line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence, but depending on the use case
      It is also possible to configure the MPU as "Write through", to guarantee the write access coherence.
      In that case, the MPU must be configured as Cacheable/Bufferable/Not Shareable.
      Even though the user must manage the cache coherence for read accesses.
      Please refer to the AN4838 “Managing memory protection unit (MPU) in STM32 MCUs”
      Please refer to the AN4839 “Level 1 cache on STM32F7 Series”

@par Directory contents 

    - STemWin/STemWin_MemoryDevice/Core/Inc/main.h			        Main program header file
    - STemWin/STemWin_MemoryDevice/Core/Inc/stm32f7xx_hal_conf.h	Library Configuration file
    - STemWin/STemWin_MemoryDevice/Core/Inc/stm32f7xx_it.h		    Interrupt handlers header file
    - STemWin/STemWin_MemoryDevice/Core/Src/main.c			        Main program file
    - STemWin/STemWin_MemoryDevice/Core/Src/stm32f7xx_it.c		    STM32F7xx Interrupt handlers
    - STemWin/STemWin_MemoryDevice/Core/Src/system_stm32f7xx.c		STM32F7xx system file
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel2.c	Wheel2 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel3.c	Wheel3 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel4.c	Wheel4 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel5.c	Wheel5 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/garage.c 	garage picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/memory_device_app.c memory devce application
    - STemWin/STemWin_MemoryDevice/STemWin/Target/GUIConf.c		Display controller initialization
    - STemWin/STemWin_MemoryDevice/STemWin/Target/GUIConf.h		Header for GUIConf.c
    - STemWin/STemWin_MemoryDevice/STemWin/Target/LCDConf.c		Configuration file for the GUI library
    - STemWin/STemWin_MemoryDevice/STemWin/Target/LCDConf.h		Header for LCDConf.c

  
@par Hardware and Software environment  

  - This application runs on STM32F769xx devices.

  - This application has been tested with STMicroelectronics STM32769I-EVAL
    eval boards and can be easily tailored to any other supported device 
    and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
  - Open your preferred toolchain 
  - Rebuild all files and load your image into target memory
  - Run the application
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
