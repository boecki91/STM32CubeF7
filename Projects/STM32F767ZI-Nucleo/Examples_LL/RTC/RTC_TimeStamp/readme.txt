/**
  @page RTC_TimeStamp RTC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/RTC/RTC_TimeStamp/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RTC example.
  ******************************************************************************
  *
  * Copyright (c) 2016 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

Configuration of the Timestamp using the RTC LL API. The peripheral initialization 
uses LL unitary service functions for optimization purposes (performance and size).

In this example, after start-up, SYSCLK is configured to the max frequency using the PLL with
HSE as clock source.

The RTC peripheral configuration is ensured by the Configure_RTC() function 
(configure of the needed RTC resources according to the used hardware CLOCK, 
PWR, RTC clock source and BackUp). You may update this function to change RTC configuration.

@note LSE oscillator clock is used as RTC clock source by default.
      The user can use also LSI as RTC clock source. The user uncomment the adequate 
      line on the main.c file.
      @code
        #define RTC_CLOCK_SOURCE_LSE  
        /* #define RTC_CLOCK_SOURCE_LSI */
      @endcode
      LSI oscillator clock is delivered by a 32 kHz RC.
      LSE (when available on board) is delivered by a 32.768 kHz crystal.

Configure_RTC_TimeStamp() function is then called to initialize the time stamp feature 
with interrupt mode. It configures the time stamp pin to be rising edge and enables
the time stamp detection on time stamp pin.
LL_RTC_DATE_Config()and LL_RTC_TIME_Config() functions are then called to initialize the 
time and the date.

The associated firmware performs the following:
1. After start-up the program configure the RTC (Time date) and enable the feature 
   timeStamp. 

2. When applying a high level on the time stamp pin (PC.13) by pressing the User push-button, 
   a time stamp event is detected and the calendar is saved in the time stamp structures.
   Each time the user presses on the User push-button, the current date and time stamp are updated and displayed 
   on the debugger (live watch) in aShowTimeStamp and aShowDateStamp variables .
   The current time and date are updated and displayed on the debugger (live watch) in aShowTime, aShowDate variables .

- LED1 is toggling : This indicates that the system generates an error.
       
@Note�If the user code size exceeds the DTCM-RAM size or starts from internal cacheable memories (SRAM1 and SRAM2),that is shared between several processors,
 �����then it is highly recommended to enable the CPU cache and maintain its coherence at application level.
������The address and the size of cacheable buffers (shared between CPU and other masters)  must be properly updated to be aligned to cache line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence, but depending on the use case
����� It is also possible to configure the MPU as "Write through", to guarantee the write access coherence.
������In that case, the MPU must be configured as Cacheable/Bufferable/Not Shareable.
������Even though the user must manage the cache coherence for read accesses.
������Please refer to the AN4838 �Managing memory protection unit (MPU) in STM32 MCUs�
������Please refer to the AN4839 �Level 1 cache on STM32F7 Series�

@par Directory contents 

  - RTC/RTC_TimeStamp/Inc/stm32f7xx_it.h          Interrupt handlers header file
  - RTC/RTC_TimeStamp/Inc/main.h                  Header for main.c module
  - RTC/RTC_TimeStamp/Inc/stm32_assert.h          Template file to include assert_failed function
  - RTC/RTC_TimeStamp/Src/stm32f7xx_it.c          Interrupt handlers
  - RTC/RTC_TimeStamp/Src/main.c                  Main program
  - RTC/RTC_TimeStamp/Src/system_stm32f7xx.c      STM32F7xx system source file


@par Hardware and Software environment

  - This example runs on STM32F767xx devices.
    
  - This example has been tested with NUCLEO-F767ZI board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
