/* Copyright Statement:
 *
 * @2015 MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek Inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE.
 */

/** 
  * @page pxp_screen example project
  * @{
  
@par Overview

  - Example project description 
    -  This example project is used to demo the basic functions of Proximity profile.
  
  - Features of the example project
    - The screen will display "Unconnected" when MT2523 disconnect with the peer device. 
    - The screen will display "Connected" when MT2523 connect with the peer device. 
    - The screen will display "Out of range" when MT2523 moves away from the peer device so that the path 
      loss increases above a preset level.  
  
@par Hardware and software environment  

  - Supported platform  
    - LinkIt 2523 HDK, LCM.
     (Detail configuration, please refer to readme.txt on the directory mt2523_hdk/apps/iot_sdk_demo/).

  - PC/environment config
    - Need a serial tool (such as hyper terminal) for UART logging.
    - Com port srtting: baudrate: 115200, data bits: 8, stop bit: 1, parity: none and flow control: off.

  - Peer test device
    - on iphone 5 or later version device, install the "LightBlue" app, which can be downloaded from App Store.


@par Directory contents 
  - Source and header files
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_gatts_srv_common.c        GATT server common function file.
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_message.c                 GATT and GAP message file.
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_static_callback.c         GATT and GAP static callback file.
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_ias.c                     GATT service IAS header file.	
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_lls.c                     GATT service LLS header file.
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_tps.c                     GATT service TPS header file.
    - mt2523_hdk/apps/iot_sdk_demo/src/pxp_screen/ble_pxp_main.c                Proximity prfile and UI main program file.   
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_pxp_main.h                Proximity prfile and UI main program header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_ias.h                     GATT service IAS header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_lls.h                     GATT service LLS header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_tps.h                     GATT service TPS header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_message.h                 BLE message header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_gatts_srv_common.h        GATT server header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_app_utils.h               BLE app utils header file.
    - mt2523_hdk/apps/iot_sdk_demo/inc/pxp_screen/ble_bds_app_util.h            BDS tool header file.

 
  
@par Run the example
  - Step-by-step instructions on how to run the example project.
    - pre-condition: Iphone's bluetooth has been power on.
    - step 1: enter pxp's screen on LinkIt 2523 HDK(you can tap "BLE PXP" on the main screen, it will show "Unconnected");
    - step 2: enter "LightBlue" app on the iphone, and connect BLE to LinkIt 2523 HDK(you can find LinkIt 2523 HDK's BLE adress or name, like "MTKdevice",
              please tap it, then it will make the BLE connection with LinkIt 2523 HDK, and iphone will enter conection page, and will show all 
              attributes(services, characteristics...) on this page, at the same time, MT2523 will show "Connected");
    - step 3: write alert level, then LinkIt 2523 HDK will have a response(on iphone connection page, you can find "immediate alert" characteristic, 
              tap it, then will enter it's operation screen. you can write value "1" or "2", which means to start alert on LinkIt 2523 HDK with middle or high level,
              of cause, in this demo LinkIt 2523 HDK will show "out of range" replace the alert because of audio is not supported;
              then you can write value "0", which means to stop alert on LinkIt 2523 HDK, then LinkIt 2523 HDK will back to "connected" screen);
    - step 4: exit pxp's screen or "LightBlue" app, then BLE connection will be destroyed. then LinkIt 2523 HDK will back to "Unconencted" screen.
  
  
  * @}
*/