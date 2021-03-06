/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/**
  * @page nghttp2 client example project
  * @{

@par Overview

 - Example project description
   - The project is a simple demonstration program to show how to use the nghttp2 API.
 - Features of the example project
   - This example demonstrates a http/2 client which connect with a web server based mbedtls, which will fallback http/1.1 if the server 
     does not support http/2.
 - Process / procedure of the example project
   - Connection to SSL server, then get homepage.
 - Output from the example
   - Nghttp2 log will show.

@par Hardware and software environment

  - Supported HDK
    - MediaTek LinkIt 7687 HDK.

  - PC/environment configuration
   - A serial tool is required, such as hyper terminal, for UART logging.
   - COM port settings : baudrate: 115200, data bits: 8, stop bit: 1, parity: none and flow control: off.
   - Prepare a Wi-Fi router wtih SSID named as SQA_TEST_AP, whose password is 77777777, and auth mode is WPA_PSK_WPA2_PSK. The Wi-Fi router has the internet connection.

@par Directory contents
  - Source and header files, e.g.,
   - mt7687_hdk/apps/nghttp2_client/src/main.c                     Main program.
   - mt7687_hdk/apps/nghttp2_client/src/system_mt7687.c            The configuration file of the Cortex-M4 with floating point core registers and system clock.
   - mt7687_hdk/apps/nghttp2_client/src/sys_init.c                 This file initializes the basic hardware environment for the system, including system clock, UART port for logging, Pinmux, cache and other necessary hardware.
   - mt7687_hdk/apps/nghttp2_client/src/sta_network.c              Network helper function for Wi-Fi station mode initialization until IP network ready.
   - mt7687_hdk/apps/nghttp2_client/src/ept_eint_var.c             The EINT configuration file generated by Easy Pinmux Tool(EPT). Please do not edit the file.
   - mt7687_hdk/apps/nghttp2_client/src/ept_gpio_var.c             The GPIO configuration file generated by Easy Pinmux Tool(EPT). Please do not edit the file.
   - mt7687_hdk/apps/nghttp2_client/inc/FreeRTOSConfig.h           FreeRTOS feature configuration file.
   - mt7687_hdk/apps/nghttp2_client/inc/hal_feature_config.h       MT76x7's feature configuration file.
   - mt7687_hdk/apps/nghttp2_client/inc/flash_map.h                MT76x7's memory layout symbol file.
   - mt7687_hdk/apps/nghttp2_client/inc/ept_eint_drv.h             The EINT configuration file generated by Easy Pinmux Tool(EPT). Please do not edit the file.
   - mt7687_hdk/apps/nghttp2_client/inc/ept_gpio_drv.h             The GPIO configuration file generated by Easy Pinmux Tool(EPT). Please do not edit the file.
   - mt7687_hdk/apps/nghttp2_client/inc/sys_init.h                 The header file of sys_init.c.
   - mt7687_hdk/apps/nghttp2_client/inc/sta_network.h              The header file of sta_network.c.
   - mt7687_hdk/apps/nghttp2_client/GCC/startup_mt7687.s           MT76x7's startup file for GCC.
   - mt7687_hdk/apps/nghttp2_client/GCC/syscalls.c                 The minimal implementation of the system calls.
   - mt7687_hdk/apps/nghttp2_client/MDK-ARM/startup_mt7687.s       MT76x7's startup file for Keil.

  - Project configuration files using GCC
   - mt7687_hdk/apps/nghttp2_client/GCC/feature.mk                 Feature configuration.
   - mt7687_hdk/apps/nghttp2_client/GCC/Makefile                   Makefile.
   - mt7687_hdk/apps/nghttp2_client/GCC/mt7687_flash.ld            Linker script.

  - Project configuration files using Keil
   - mt7687_hdk/apps/nghttp2_client/MDK-ARM/nghttp2_client.uvprojx uVision5 Project File. Contains the project structure in XML format.
   - mt7687_hdk/apps/nghttp2_client/MDK-ARM/nghttp2_client.uvoptx  uVision5 project options. Contains the settings for the debugger, trace configuration, breakpoints, currently open files, etc.
   - mt7687_hdk/apps/nghttp2_client/MDK-ARM/flash.sct              Linker script.

@par Run the demo
  - Connect the board to PC with serial port cable.
  - Build the example project with the command, "./build.sh mt7687_hdk nghttp2_client" under the SDK root folder and download the nghttp2_client.bin file to LinkIt 7687 HDK.
  - Power on LinkIt 7687 HDK. It will show nghttp2 log, such as "nghttp2clientTestTask".

* @}
*/
