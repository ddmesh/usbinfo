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

#include <iostream>
#include "usbinfo_common.h"
#include <stdio.h>


using namespace std;

void printdev(libusb_device* dev); //prototype of the function

void print_header()
{
  cerr << "Prints addtional USB infos" << endl;
  cerr << "Copyright 2023 Stephan Enderlein (BSD-3-Clause license)" << endl << endl;
}

int main()
{
  int r; //for return values

  libusb_device** devs; //pointer to pointer of device, used to retrieve a list of devices
  libusb_context* ctx = NULL; //a libusb session
  ssize_t cnt; //holding number of devices in list

  print_header();

  r = libusb_init(&ctx); //initialize a library session

  if (r < 0)
  {
    cerr << "Init Error " << r << endl; //there was an error
    exit(1);
  }

//  libusb_set_option(ctx, LIBUSB_OPTION_LOG_LEVEL, 3); //set verbosity level to 3, as suggested in the documentation

  cnt = libusb_get_device_list(ctx, &devs); //get the list of devices
  if (cnt < 0)
  {
    cerr << "Get Device Error" << endl; //there was an error
    exit(1);
  }

  cout << cnt << " Devices in list." << endl; //print total number of usb devices

  for (int i = 0; i < cnt; i++)
  {
    printdev(devs[i]); //print specs of this device
  }

  libusb_free_device_list(devs, 1); //free the list, unref the devices in it
  libusb_exit(ctx); //close the session


  // following is optional and can be used to filter some infos for specific devices.


  // lookup via "interface name"
  char buf[PATH_MAX];
  cout << "---- 0x1234 via string ---- " << endl;
  r = usb_lookupAcmDevice(buf, sizeof(buf), 0x1234, 0, "command", 0);
  if (r < 0) { cout << "command: no device" << endl; }
  else { cout << "==> command: " << buf << endl; }

  r = usb_lookupAcmDevice(buf, sizeof(buf), 0x1234, 0, "rfid", 0);
  if (r < 0) { cout << "rfid: no device" << endl; }
  else { cout << "==> rfid: " << buf << endl; }

  r = usb_lookupAcmDevice(buf, sizeof(buf), 0x1234, 0, "reserved", 0);
  if (r < 0) { cout << "reserved: no device" << endl; }
  else { cout << "==> reserved: " << buf << endl; }

  // lookup via interface number
  cout << endl << "---- 0x1234 via interfaces ---- " << endl;
  for (int i = 0; i < 6; i++)
  {
    r = usb_lookupAcmDevice(buf, sizeof(buf), 0x1234, 0, NULL, i);
    if (r < 0) { cout << i << ": no device" << endl; }
    else { cout << i << ": ==> " << buf << endl; }
  }
}



void printdev(libusb_device* dev)
{
  libusb_device_descriptor desc;
  int ret = 0;

  ret = libusb_get_device_descriptor(dev, &desc);
  if (ret < 0)
  {
    cout << "failed to get device descriptor" << endl;
    return;
  }

  cout << "Number of possible configurations: " << (int)desc.bNumConfigurations << "  ";
  cout << "Device Class: " << (int)desc.bDeviceClass << "  ";
  cout << "VendorID: " << hex << desc.idVendor << "  ";
  cout << "ProductID: " << hex << desc.idProduct << endl;

  // open usb device to request strings
  libusb_device_handle* devh = NULL;
  ret = libusb_open(dev, &devh);
  if (ret)
  {
    cerr << "error: libusb_open" << endl;
    return;
  }

  for (int cfg = 0; cfg < desc.bNumConfigurations; cfg++)
  {
    libusb_config_descriptor* config;
    ret = libusb_get_config_descriptor(dev, cfg, &config);
    if (ret)
    {
      cerr << "error: libusb_get_config_descriptor" << endl;
      return;
    }

    cout << "Interfaces: " << (int)config->bNumInterfaces << endl;

    for (int i = 0; i < (int)config->bNumInterfaces; i++)
    {
      const libusb_interface* inter = &config->interface[i];
      cout << "  Number of alternate settings: " << inter->num_altsetting << endl;

      for (int j = 0; j < inter->num_altsetting; j++)
      {
        const libusb_interface_descriptor* interdesc = &inter->altsetting[j];
        cout << "- [" << i << "] Interface Number: " << (int)interdesc->bInterfaceNumber << " | ";

        char buf[64];
        ret = usb_getDevicePath(buf, sizeof(buf), dev, &desc, config->bConfigurationValue, interdesc->bInterfaceNumber);
        if (ret == 0)
        {
          cout << "path: /sys/bus/usb/devices/" << buf;

          char tty[32];
          ret = usb_getAcmDeviceName(tty, sizeof(tty), buf);
          if (ret == 0)
          {
            cout << " [ tty path: /dev/" << tty << " ]";
          }
        }
        else { cout << "dev path: error"; }

        unsigned char iface_str[64] = {};
        ret = libusb_get_string_descriptor_ascii(devh, interdesc->iInterface, iface_str, sizeof(iface_str));
        if (ret > 0)
        {
          cout << " | Name:  [" << (int)interdesc->iInterface << "] \"" << iface_str << "\"";
        }

        cout << endl;
        cout << "    Number of endpoints: " << (int)interdesc->bNumEndpoints << endl;

        for (int k = 0; k < (int)interdesc->bNumEndpoints; k++)
        {
          const libusb_endpoint_descriptor* epdesc = &interdesc->endpoint[k];

          const char* eType = "";
          switch (epdesc->bmAttributes & 0x3)
          {
            case LIBUSB_TRANSFER_TYPE_CONTROL: eType = "ctrl"; break;
            case LIBUSB_TRANSFER_TYPE_ISOCHRONOUS: eType = "iso"; break;
            case LIBUSB_TRANSFER_TYPE_BULK: eType = "bulk"; break;
            case LIBUSB_TRANSFER_TYPE_INTERRUPT: eType = "interrupt"; break;
          }

          const char* eIsoType = "";
          switch (epdesc->bmAttributes >> 2 & 0x3)
          {
            case LIBUSB_ISO_SYNC_TYPE_NONE: eIsoType = "none"; break;
            case LIBUSB_ISO_SYNC_TYPE_ASYNC: eIsoType = "async"; break;
            case LIBUSB_ISO_SYNC_TYPE_ADAPTIVE: eIsoType = "adapt"; break;
            case LIBUSB_ISO_SYNC_TYPE_SYNC: eIsoType = "sync"; break;
          }
          const char* eIsoUsage = "";
          switch (epdesc->bmAttributes >> 4 & 0x3)
          {
            case LIBUSB_ISO_USAGE_TYPE_DATA: eIsoUsage = "data"; break;
            case LIBUSB_ISO_USAGE_TYPE_FEEDBACK: eIsoUsage = "feedback"; break;
            case LIBUSB_ISO_USAGE_TYPE_IMPLICIT: eIsoUsage = "implicit"; break;
            default: eIsoUsage = "-"; break;
          }

          const char* dir = "";
          dir = (epdesc->bEndpointAddress & 0x80) ? "in" : "out";

          if ((epdesc->bmAttributes & 0x3) == LIBUSB_TRANSFER_TYPE_ISOCHRONOUS)
          {
            printf("      %2u:descriptor type: %2x | EP address: %2x (%3s) | maxPktSize: %4u | type: %s (isoType: %s, isoUsage: %s)\n"
              , k
              , epdesc->bDescriptorType
              , epdesc->bEndpointAddress, dir
              , epdesc->wMaxPacketSize
              , eType, eIsoType, eIsoUsage);
          }
          else
          {
            printf("      %2u:descriptor type: %2x | EP address: %2x (%3s) | maxPktSize: %4u | type: %s\n"
              , k
              , epdesc->bDescriptorType
              , epdesc->bEndpointAddress, dir
              , epdesc->wMaxPacketSize
              , eType);
          }

        }
        cout << endl;
      }
      cout << endl;
    }// for interface

    cout << endl;

    libusb_free_config_descriptor(config);
  } //for config

  libusb_close(devh);

}
