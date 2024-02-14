/*
Copyright (c) 2023, Stephan Enderlein. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/
/*!
************************************************************************
*
* @file usbinfo_common.h
*
* @brief helper functions to access usblib infos
*
* @author Stephan Enderlein
*
************************************************************************/


#ifndef _INCLUDED_USBINFO_COMMON_H_
#define _INCLUDED_USBINFO_COMMON_H_

#include <libusb-1.0/libusb.h>


#ifdef __cplusplus
extern "C" {
#endif

// path : buffer for device path (min 64bytes)
  int usb_getDevicePath(char* path, uint16_t len, libusb_device* dev, libusb_device_descriptor* desc, uint8_t configuration, uint8_t interface);

  int usb_getAcmDeviceName(char* buf, uint16_t len, const char* devpath);

  int usb_lookupAcmDevice(char* ttyDevPath, uint16_t len, uint16_t idVendor, uint16_t idProduct, const char* ifaceName, uint8_t ifaceNum);

#ifdef __cplusplus
}
#endif


#endif // _INCLUDED_USBINFO_COMMON_H_
