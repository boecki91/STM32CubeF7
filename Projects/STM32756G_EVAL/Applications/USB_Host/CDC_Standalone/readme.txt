/**
  @page CDC_Standalone USB Host Communication Class (CDC) application

  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    USB_Host/CDC_Standalone/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the USB Host CDC application.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. All rights reserved.
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

Use of the USB host application based on the CDC class.

This is a typical application on how to use the STM32F7xx USB OTG Host peripheral to operate with an USB
CDC device application based on the two CDC transfer directions with a dynamic serial configuration:

 - Transmission:
   The user can select in the Host board, using the menu, a file among the ones available on the SD
   and send it to the Device board. The content of the file could be visualized through the Hyperterminal
   (the link configuration is imposed initially by the device and could be checked using the
   configuration menu). Data to be transmitted is stored in CDC_TX_Buffer buffer.

 - Reception:
   The data entered by the user using the Hyperterminal in ASCII format are transferred by the device
   board to the Host board and displayed on its LCD screen. The CDC_RX_Buffer is the buffer used for
   data reception.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config()
function to configure the system clock (SYSCLK) to run at 200 Mhz. The Full Speed (FS) USB module uses
internally a 48-MHz clock which is coming from a specific output of two PLLs: main PLL or PLL SAI.
In the High Speed (HS) mode the USB clock (60 MHz) is driven by the ULPI.

When the application is started, the connected USB CDC device is detected in CDC mode and gets
initialized. The STM32 MCU behaves as a CDC Host, it enumerates the device and extracts VID, PID,
manufacturer name, Serial no and product name information and displays it on the LCD screen.

A menu is displayed and the user can select any operation from the menu using the Joystick buttons:
 - "Send Data" operation starts the Data Transmission.
 - "Receive Data" operation starts the Data Reception.
 - "Configuration" operation defines the desired Host CDC configuration (Baudrate,Parity, DataBit and StopBit)
   The baudrate comes with a default value of 115,2 kbps (BAUDRATE = 115200).
 - "Re-Enumerate" operation performs a new Enumeration of the device.

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

For more details about the STM32Cube USB Host library, please refer to UM1720
"STM32Cube USB Host library".


@par USB Library Configuration

To select the appropriate USB Core to work with, user must add the following macro defines within the
compiler preprocessor (already done in the preconfigured projects provided with this application):
      - "USE_USB_HS" when using USB High Speed (HS) Core
      - "USE_USB_FS" when using USB Full Speed (FS) Core
      - "USE_USB_HS" and "USE_USB_HS_IN_FS" when using USB High Speed (HS) Core in FS mode

It is possible to fine tune needed USB Host features by modifying defines values in USBH configuration
file �usbh_conf.h� available under the project includes directory, in a way to fit the application
requirements, such as:
- Level of debug: USBH_DEBUG_LEVEL
                  0: No debug messages
                  1: Only User messages are shown
                  2: User and Error messages are shown
                  3: All messages and internal debug messages are shown
   By default debug messages are displayed on the debugger IO terminal; to redirect the Library
   messages on the LCD screen, lcd_log.c driver need to be added to the application sources.


@par Keywords

Connectivity, USB Host, Full Speed, High Speed, CDC, PSTN, HyperTerminal, VCP, Com port,

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

  - USB_Host/CDC_Standalone/Src/main.c                  Main program
  - USB_Host/CDC_Standalone/Src/sd_diskio.c             FatFs sd diskio driver implementation
  - USB_Host/CDC_Standalone/Src/system_stm32f7xx.c      STM32F7xx system clock configuration file
  - USB_Host/CDC_Standalone/Src/stm32f7xx_it.c          Interrupt handlers
  - USB_Host/CDC_Standalone/Src/menu.c                  CDC State Machine
  - USB_Host/CDC_Standalone/Src/usbh_conf.c             General low level driver configuration
  - USB_Host/CDC_Standalone/Src/explorer.c              Explore the uSD content
  - USB_Host/CDC_Standalone/Src/cdc_configuration.c     CDC settings State Machine
  - USB_Host/CDC_Standalone/Src/cdc_receive.c           CDC Receive State Machine
  - USB_Host/CDC_Standalone/Src/cdc_send.c              CDC Send State Machine
  - USB_Host/CDC_Standalone/Inc/main.h                  Main program header file
  - USB_Host/CDC_Standalone/Inc/sd_diskio.h             FatFs sd diskio driver header file
  - USB_Host/CDC_Standalone/Inc/stm32f7xx_it.h          Interrupt handlers header file
  - USB_Host/CDC_Standalone/Inc/lcd_log_conf.h          LCD log configuration file
  - USB_Host/CDC_Standalone/Inc/stm32f7xx_hal_conf.h    HAL configuration file
  - USB_Host/CDC_Standalone/Inc/usbh_conf.h             USB Host driver Configuration file
  - USB_Host/CDC_Standalone/Inc/ffconf.h                FAT file system module configuration file


@par Hardware and Software environment

  - This application runs on STM32F756xx/STM32F746xx devices.

  - This application has been tested with STMicroelectronics STM327x6G_EVAL RevB
    evaluation boards and can be easily tailored to any other supported device
    and development board.

  - STM327x6G_EVAL RevB Set-up
    - Insert a microSD card into the STM327x6G_EVAL uSD slot (CN16)
    - Plug the CDC device into the STM327x6G_EVAL board through 'USB micro A-Male
      to B-Male' cable to the connector:
      - CN8 : to use USB High Speed (HS)
      - CN13: to use USB Full Speed (FS)
      - CN14: to use USB HS-IN-FS.
              Note that some FS signals are shared with the HS ULPI bus, so some PCB rework is needed.
              For more details, refer to section "USB OTG2 HS & FS" in STM327x6G_EVAL Evaluation Board
              User Manual.
        @note Make sure that :
         - jumper JP8 must be removed when using USB OTG FS
     - on HOST board JP14 and JP20 are fitted on 2-3 position and on 1-2 position on Device board

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - In the workspace toolbar select the project configuration:
   - STM327x6G_EVAL_USBH-HS: to configure the project for STM32F7xx devices using USB OTG HS peripheral
   - STM327x6G_EVAL_USBH-FS: to configure the project for STM32F7xx devices using USB OTG FS peripheral
   - STM327x6G_EVAL_USBH-HS-IN-FS: to configure the project for STM32F7xx devices and use USB OTG HS
                                   peripheral In FS (using embedded PHY).
 - Run the application

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
