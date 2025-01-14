/**
  @page LwIP_StreamingServer   LwIP Streaming Server Socket RTOS Application
 
  @verbatim
  ******************************************************************************
  * @file    LwIP/LwIP_StreamingServer/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of LwIP Streaming Server application
  ******************************************************************************
  *
  * Copyright (c) 2016 STMicroelectronics International N.V. All rights reserved.
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


This application guides STM32Cube HAL API STM32Cube firmware with LwIP, LibJPEG and FreeRTOS middleware components 
to run a streaming server based on Netconn API of LwIP TCP/IP stack.

This application aims to encode the stream video RGB888 received from the camera
to JPEG format using LibJPEG. Then, the JPEG frames are sent through Ethernet peripheral
using the RTP protocol (Real-time Transport Protocol) to a remote client for example 
VLC media player. The RTSP protocol (Real Time Streaming Protocol) is used to control 
media sessions (SETUP, PLAY, TEARDOWN).

To understand messages received from the remote media player, this application implements
the RTSP server protocol. Also, it implements the RTP protocol for sending the MJEPG frames
to the media player.

To run this application, you need to:
    -Type the URL (rtsp://192.168.0.10) on the VLC media player (Media/Open Network Stream/Open Media window) 
    -It is recommended that the caching value is set to 100ms on the VLC to keep the stream running smoothly
     (Media/Open Network Stream/Open Media window => Show more options), then press Play on VLC Play button. 

The following libraries are used in the application:
	-LwIP stack: TCP/IP protocols stack
	-LibJPEG:    JPEG encoding/decoding library
	-FreeRTOS:   Real Time Operating System
        
If the LCD is used (#define USE_LCD in main.h), log messages will be displayed 
to inform user about camera initialization and ethernet cable status and the IP address value, else this 
will be ensured by LEDs:
  + LED1: ethernet cable is connected.
  + LED3: ethernet cable is not connected.

Note: In this application the Ethernet Link ISR need the System tick interrupt 
to configure the Ethernet MAC, so the Ethernet Link interrupt priority must be 
set lower (numerically greater) than the Systick interrupt priority to ensure 
that the System tick increments while executing the Ethernet Link ISR.

Note: By default, the Ethernet Half duplex mode is not supported in the 
STM32F769I-EVAL board, for more information refer to the HAL_ETH_MspInit() 
function in the ethernetif.c file.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@note The STM32F7xx devices can reach a maximum clock frequency of 216MHz but as this application uses SDRAM,
      the system clock is limited to 200MHz. Indeed proper functioning of the SDRAM is only guaranteed 
      at a maximum system clock frequency of 200MHz.

For more details about this application, refer to UM1713 "STM32Cube interfacing with LwIP and applications
 

@par Directory contents

  - LwIP_StreamingServer/Inc/app_ethernet.h               header of app_ethernet.c file
  - LwIP_StreamingServer/Inc/encode.h                     header for encode.c 
  - LwIP_StreamingServer/Inc/ethernetif.h                 header for ethernetif.c file
  - LwIP_StreamingServer/Inc/FreeRTOSConfig.h             FreeRTOS configuration options
  - LwIP_StreamingServer/Inc/jconfig.h                    LibJPEG configuration
  - LwIP_StreamingServer/Inc/jmorecfg.h                   LibJPEG configuration  
  - LwIP_StreamingServer/Inc/lwipopts.h                   LwIP stack configuration options
  - LwIP_StreamingServer/Inc/lcd_log_conf.h               LCD Log configuration file
  - LwIP_StreamingServer/Inc/main.h                       Main program header file
  - LwIP_StreamingServer/Inc/rtp_protocol.h               header for rtp_protocol.c
  - LwIP_StreamingServer/Inc/rtsp_protocol.h              header for rtsp_protocol.c
  - LwIP_StreamingServer/Inc/s5k5cag_RGB888.h             header for s5k5cag_RGB888.c
  - LwIP_StreamingServer/Inc/stm32f7xx_hal_conf.h         HAL configuration file
  - LwIP_StreamingServer/Inc/stm32f7xx_it.h               Interrupt handlers header file
  - LwIP_StreamingServer/Inc/jdata_conf.h                 Write/Read methods definition
  - LwIP_StreamingServer/Inc/stm32f769i_camera.h          header for stm32f769i_camera.c
  - LwIP_StreamingServer/Src/app_ethernet.c               Ethernet specific module
  - LwIP_StreamingServer/Src/encode.c                     Encoding to JPEG
  - LwIP_StreamingServer/Src/ethernetif.c                 Interfacing LwIP to ETH driver
  - LwIP_StreamingServer/Src/main.c                       Main program
  - LwIP_StreamingServer/Src/rtp_protocol.c               RTP protocol functions
  - LwIP_StreamingServer/Src/rtsp_protocol.c              RTSP protocol functions
  - LwIP_StreamingServer/Src/s5k5cag_RGB888.c             S5K5CAG camera driver
  - LwIP_StreamingServer/Src/stm32f7xx_it.c               Interrupt handlers
  - LwIP_StreamingServer/Src/stm32f769i_camera.c          camera driver interface
  - LwIP_StreamingServer/Src/system_stm32f7xx.c           STM32F7xx system clock configuration file
  - LwIP_StreamingServer/Src/stm32f7xx_hal_timebase_tim.c HAL time base based on the hardware TIM Template


@par Hardware and Software environment

  - This application runs on STM32F767xx/STM32F769xx/STM32F777xx/STM32F779xx devices.
    
  - This application has been tested with the following environments:
     - STM32F769I-EVAL board and can be easily tailored to any other 
       supported device and development board.
     - RTSP/RTP clients: VLC media player
     
      
  - STM32F769I-EVAL Set-up
    - Connect the eval board to your local network through a straight ethernet cable
    - jumper JP3 must be on the position 2-3 (ETH signal)
    - jumper JP6 must be on the position 2-3 (ETH signal)
    - jumper JP8 must be on the position 1-2 (MII_MDC signal) 
    - jumper JP12 must be on the position 1-2 (ETH signal) 
    - jumper JP10 not fitted (FMC_NE1 signal)
     
  - Remote PC Set-up
    - Configure a static IP address for your remote PC 
      The IP address must be 192.168.0.11


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the application

  * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
  */