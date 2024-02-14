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
* @file usbinfo.cpp
*
* @brief simple utility to get some more info about usb devices
// sudo apt install libusb-dev
// sudo apt install libudev-dev
// c++ usbinfo.cpp -lusb-1.0

* @author Stephan Enderlein
*
************************************************************************/

#include "usbinfo_common.h"
#include <libusb-1.0/libusb.h>
#include <string.h>
#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>


// path : buffer for device path (min 64bytes)
int usb_getDevicePath(char* path, uint16_t len, libusb_device* dev, libusb_device_descriptor* desc, uint8_t configuration, uint8_t interface)
{
  if (!dev || !desc || !path || len == 0)
  {
    return -1;
  }

  uint8_t bus = libusb_get_bus_number(dev);

  //get device path
  uint8_t ports[7] = {}; // maximum length of the array. As per the USB 3.0 specs,
                        // the current maximum limit for the depth is 7.
  int nports = libusb_get_port_numbers(dev, ports, sizeof(ports));
  if (nports < 0)
  {
    return -1;
  }

  char sports[32] = {}; // 7 numbers * (2 digits) + 7*'.' + '\0'
  char tmp[33] = {};
  for (int p = 0; nports > 0 && p < nports; p++)
  {
    if (p != 0)
    {
      strcat(sports, ".");
    }
    snprintf(tmp, sizeof(tmp), "%u", ports[p]);
    strcat(sports, tmp);
  }
  snprintf(path, len, "%u-%s:%u.%u", bus, sports, configuration, interface);

  return 0;
}

int usb_getAcmDeviceName(char* buf, uint16_t len, const char* devpath)
{
  char directory[PATH_MAX];

  // we are looking for tty, so add 'tty' (which is an existing subdir)
  snprintf(directory, sizeof(directory), "/sys/bus/usb/devices/%s/tty", devpath);

  // open directory
  DIR* d = opendir(directory);
  if (!d)
  {
    return -1;
  }

// loop through entries
  struct dirent* entry;
  while ( (entry = readdir(d)) > 0)
  {
    if (strncmp(entry->d_name, "ttyACM", 6) == 0)
    {
      strncpy(buf, entry->d_name, len);
      return 0;
    }
  }

  return -1;
}

// ifaceName if NULL, then check for ifaceNum is done
int usb_lookupAcmDevice(char* ttyDevPath, uint16_t len, uint16_t idVendor, uint16_t idProduct, const char* ifaceName, uint8_t ifaceNum)
{

  libusb_context* ctx = NULL; //a libusb session
  libusb_device** devs; //pointer to pointer of device, used to retrieve a list of devices

  int ret = 0; //for return values
  ssize_t cnt; //holding number of devices in list

  if (!ttyDevPath || !len)
  {
    return -1;
  }

  memset(ttyDevPath, 0, len);

  //initialize a library session
  ret = libusb_init(&ctx);
  if (ret < 0)
  {
    return -2;
  }

// libusb_set_option(ctx, LIBUSB_OPTION_LOG_LEVEL, 3); //set verbosity level to 3, as suggested in the documentation

 //get the list of devices
  cnt = libusb_get_device_list(ctx, &devs);
  if (cnt < 0)
  {
    return -3;
  }
//printf("device count:%lu\n", cnt);
  // run through all devices
  int run = 1;
  int ttyfound = 0;
  for (int dev = 0; run && dev < cnt; dev++)
  {
    libusb_device_descriptor desc;
    ret = libusb_get_device_descriptor(devs[dev], &desc);
    if (ret < 0)
    {
      ret = -4; run = 0; break;
    }
//printf("got devdesc (dev:%d)\n", dev);
    // check vendor/product
    if (desc.idVendor == idVendor && (idProduct == 0 || desc.idProduct == idProduct))
    {
      libusb_device_handle* devh = NULL;

      // open usb device to request strings
      ret = libusb_open(devs[dev], &devh);
      if (ret)
      {
        ret = -4; run = 0; break;
      }

      // run through all device configs
      for (int cfg = 0; run && cfg < desc.bNumConfigurations; cfg++)
      {
        libusb_config_descriptor* config;
        ret = libusb_get_config_descriptor(devs[dev], cfg, &config);
        if (ret)
        {
          ret = -5; run = 0; break;
        }
//printf("got cfg desc (cfg:%d)\n", cfg);
        // run though all interface for current config
        for (int iface = 0; run && iface < (int)config->bNumInterfaces; iface++)
        {
          const libusb_interface* inter = &config->interface[iface];
//printf("iface:%d\n", iface);
          for (int alt = 0; alt < inter->num_altsetting; alt++)
          {
            const libusb_interface_descriptor* interdesc = &inter->altsetting[alt];
            int found = 0;
//printf("alt:%d\n", alt);
            // check interface name. BUT only request valid interface indexes
            // string iInterface = 0 is special (requesting language id)
            if (interdesc->iInterface > 0)
            {
              // optional either interface name check or endpoint
              if (ifaceName)
              {
                unsigned char iface_str[64] = {};

                ret = libusb_get_string_descriptor_ascii(devh, interdesc->iInterface, iface_str, sizeof(iface_str));
                //if(ret > 0)printf("ret:%d - %s:%s\n",ret,iface_str, ifaceName);
                if (ret > 0 && !strcmp((const char*)iface_str, ifaceName))
                {
                  found = 1;
                }
                else
                {
                  continue;
                }  // try next alt
              }
              else
              {
                if (ifaceNum == interdesc->bInterfaceNumber)
                {
                  found = 1;
                }
     //printf("ifaceNum %d, interdesc->bInterfaceNumber %d, found %d\n", ifaceNum , interdesc->bInterfaceNumber, found);
              }
            } // if(valid interface string index)

            if (found)
            {
              // get tty
              char buf[64];
              ret = usb_getDevicePath(buf, sizeof(buf), devs[dev], &desc, config->bConfigurationValue, interdesc->bInterfaceNumber);
              if (ret)
              {
                continue;
              }  // error; try next
  //printf("buf:%s\n", buf);
              char tty[32];
              ret = usb_getAcmDeviceName(tty, sizeof(tty), buf);
              if (ret)
              {
                continue;
              }  // error; try next
  //printf("tty:%s\n", tty);
              strncpy(ttyDevPath, tty, len);

              ttyfound = 1;
              run = 0;
              break;
            } // if(found)

          } //for(altsettings)
        } //for(interfaces)

        libusb_free_config_descriptor(config);

      } // for (configs)

      libusb_close(devh);

    } // if(vendor/product)
  } // for (devices)

  libusb_free_device_list(devs, 1); //free the list, unref the devices in it
  libusb_exit(ctx); //close the session

  if (!ttyfound) ret = -6;

//printf("ret=%d\n", ret);
  return ret;
}
