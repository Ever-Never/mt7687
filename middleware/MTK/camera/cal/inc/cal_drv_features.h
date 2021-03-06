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

#ifndef __CAL_DRV_FEATURES_H__
#define __CAL_DRV_FEATURES_H__

#include "isp_hw_feature_def.h"
//#include "drv_sw_features_jpeg.h"

#define __CAL_PROFILING_ENABLE__
#define __CAL_TRACE_ENABLE__
#undef __CAL_DUAL_CAMERA_SUPPORT__
#undef __CAL_CAMERA_OVERLAY_SUPPORT__
#undef __CAL_CAMERA_AF_SUPPORT__
#undef __CAL_CAMERA_LENS_SUPPORT__
#undef __CAL_HW_JPEG_ENCODE_SUPPORT__
#undef __CAL_CAMERA_RAW_SENSOR_SUPPORT__
#undef __CAL_CAMERA_CCT_SUPPORT__
#undef __CAL_CAMERA_BINNING_SUPPORT__
#undef __CAL_CAMERA_SW_Y2R_DITHERING_FOR_QV_SUPPORT__
#undef __CAL_NEED_SW_ROTATE__
#undef __CAL_GET_PREVIEW_IMAGE_SUPPORT__
#undef __CAL_MATV_SUPPORT__
#undef __CAL_NVRAM_NEED_READ__
#undef __CAL_CAMERA_CAPTURE_WALLPAPER_ROTATE_SUPPORT__
#undef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
#undef __CAL_IMAGE_ROTATE_SUPPORT__
#define __CAL_FAST_DIGITAL_ZOOM_SUPPORT__
#define __CAL_IMAGE_RESIZE_RGB_SUPPORT__
#define __CAL_IMAGE_ROTATE_RGB_SUPPORT__
#define __CAL_MDP_QV_THUMBNAIL_OUTPUT_SUPPORT__
#define __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__
#undef __CAL_MINIMIZE_GLOBAL_VARIABLE__
#undef __CAL_CAMERA_VIDEO_MJPEG_SUPPORT__
#undef __CAL_STILL_CAPTURE_ROTATE_SUPPORT__
#undef __CAL_QUICK_VIEW_IMAGE_ROTATE_SUPPORT__
#define __CAL_HW_QUICKVIEW_THUMBNAIL_SUPPORT__
#undef __CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__
#undef __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
#undef __CAL_IMAGE_ROTATE_ONLY_UYVY422_SUPPORT__  // ????

#if defined(USE_UYVY422_BETWEEN_MDP_LCD)
#define __CAL_QUICKVIEW_ONLY_UYVY422_SUPPORT__
#endif

#if defined(MT2523)
    #undef __CAL_PROFILING_ENABLE__
    #undef __CAL_TRACE_ENABLE__
    #undef __CAL_IMAGE_RESIZE_RGB_SUPPORT__
    #undef __CAL_IMAGE_ROTATE_RGB_SUPPORT__
    #undef __CAL_MDP_QV_THUMBNAIL_OUTPUT_SUPPORT__
    #undef __CAL_IMAGE_RESIZE_UYVY422_SUPPORT__
    #define __CAL_MINIMIZE_GLOBAL_VARIABLE__
    #undef __CAL_HW_QUICKVIEW_THUMBNAIL_SUPPORT__
    #define __CAL_THUMBNAIL_ONLY_YUV420_SUPPORT__
    #define __CAL_IMAGE_ROTATE_ONLY_UYVY422_SUPPORT__
#endif

#ifdef DUAL_CAMERA_SUPPORT
    #define __CAL_DUAL_CAMERA_SUPPORT__
#endif

#ifdef __ISP_CAPTURE_MODE_ADD_FRAME_SUPPORT__
    #define __CAL_CAMERA_OVERLAY_SUPPORT__
#endif

#ifdef AF_SUPPORT
    #define __CAL_CAMERA_AF_SUPPORT__
    #ifdef RAW_MAIN_CAMERA
        #define __CAL_CAMERA_LENS_SUPPORT__
    #endif
#endif

#ifdef __JPEG_ENC_HW_SUPPORTED__
    #define __CAL_HW_JPEG_ENCODE_SUPPORT__
#endif

#ifdef RAW_MAIN_CAMERA
    #define __CAL_CAMERA_RAW_SENSOR_SUPPORT__
    #define __CAL_CAMERA_CCT_SUPPORT__
    #define __CAL_CAMERA_BINNING_SUPPORT__
#endif

#ifndef __CAMERA_NVRAM_REDUCTION__
    #define __CAL_NVRAM_NEED_READ__
#endif

#define __CAL_CAMERA_CAPTURE_WALLPAPER_ROTATE_SUPPORT__

#if defined(MT2523)
    #undef __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
#else
    #define __CAL_CAMERA_VIDEO_ROTATE_SUPPORT__
#endif

#if (defined(__CAL_NEED_SW_ROTATE__)||defined(__CAL_CAMERA_CAPTURE_WALLPAPER_ROTATE_SUPPORT__)||defined(__CAL_CAMERA_VIDEO_ROTATE_SUPPORT__))
    #define __CAL_IMAGE_ROTATE_SUPPORT__
#endif

#define __CAL_QUICK_VIEW_IMAGE_ROTATE_SUPPORT__

#if (defined(MT2523) && defined(__LOW_COST_SUPPORT_COMMON__))
   #define __CAL_CAPTURE_RAW_DATA_SUPPORT__
#endif

#endif /* __CAL_DRV_FEATURES_H__ */

