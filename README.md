# Diagtask

**Version**: 1.0.0<br/>
**Author**: Stephan Enderlein<br/>
**License**: BSD-3-Clause

**Description**:
This tool displays addtional USB information and can be helpful for developments.
It lists all attached USB devices with additional informations from USB descriptor (interface, endpoints, type, device path).

The code contains an optional section that can be adapted to filter specific devices
only by passing the interface name (included in USB descriptor) or the interface number (index). \
See: "usbinfo.cpp:100"


**Example Output**

~~~
28 Devices in list.
Number of possible configurations: 1  Device Class: 9  VendorID: 1d6b  ProductID: 3
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/6-:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    4 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 1d6b  ProductID: 2
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/5-:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    4 | type: interrupt



Number of possible configurations: 2  Device Class: 0  VendorID: bda  ProductID: 8153
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-2.4:1.0
    Number of endpoints: 3
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 1024 | type: bulk
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize: 1024 | type: bulk
       2:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:    2 | type: interrupt



Interfaces: 2
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-2.4:2.0 | Name:  [5] "CDC Communications Control"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   16 | type: interrupt


  Number of alternate settings: 2
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/4-2.4:2.1
    Number of endpoints: 0

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/4-2.4:2.1 | Name:  [4] "Ethernet Data"
    Number of endpoints: 2
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 1024 | type: bulk
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize: 1024 | type: bulk



Number of possible configurations: 1  Device Class: 9  VendorID: 5e3  ProductID: 626
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-2.3.2.4:1.0 | Name:  [1] "GenesysLogic"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    2 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 5e3  ProductID: 626
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-2.3.2:1.0 | Name:  [1] "GenesysLogic"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    2 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: bda  ProductID: 413
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-2.3:1.0 | Name:  [5] "Interrupt In Interface"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    2 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: bda  ProductID: 487
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-2:1.0 | Name:  [5] "Interrupt In Interface"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    2 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 1d6b  ProductID: 3
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/4-:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    4 | type: interrupt



Number of possible configurations: 1  Device Class: 0  VendorID: 413c  ProductID: b06e
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.5:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:   64 | type: interrupt



Number of possible configurations: 1  Device Class: 0  VendorID: 413c  ProductID: b06f
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.5:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:   64 | type: interrupt



Number of possible configurations: 1  Device Class: 0  VendorID: 413c  ProductID: 2113
Interfaces: 2
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.3.2:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    8 | type: interrupt


  Number of alternate settings: 1
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.3.2:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:    8 | type: interrupt



Number of possible configurations: 1  Device Class: 0  VendorID: 413c  ProductID: 250e
Interfaces: 3
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.3.1:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    8 | type: interrupt


  Number of alternate settings: 1
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.3.1:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:   32 | type: interrupt


  Number of alternate settings: 1
- [2] Interface Number: 2 | path: /sys/bus/usb/devices/3-2.3.3.1:1.2
    Number of endpoints: 1
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:   15 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 3f0  ProductID: 2512
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.3:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt



Number of possible configurations: 1  Device Class: ef  VendorID: 45e  ProductID: 779
Interfaces: 4
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.0 | Name:  [4] "Microsoft? LifeCam HD-3000"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:    8 | type: interrupt


  Number of alternate settings: 7
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 0

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  128 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  256 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  512 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 1024 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 3072 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 5120 | type: iso (isoType: async, isoUsage: data)


  Number of alternate settings: 1
- [2] Interface Number: 2 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.2
    Number of endpoints: 0


  Number of alternate settings: 2
- [3] Interface Number: 3 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.3
    Number of endpoints: 0

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/3-2.3.2.4.4:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:  256 | type: iso (isoType: async, isoUsage: data)



Number of possible configurations: 1  Device Class: 0  VendorID: 13fd  ProductID: 1840
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2.4.3:1.0
    Number of endpoints: 2
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  512 | type: bulk
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize:  512 | type: bulk



Number of possible configurations: 1  Device Class: ff  VendorID: 9710  ProductID: 7830
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2.4.2:1.0
    Number of endpoints: 3
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  512 | type: bulk
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize:  512 | type: bulk
       2:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   16 | type: interrupt



Number of possible configurations: 1  Device Class: ff  VendorID: 1a86  ProductID: 7523
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2.4.1:1.0
    Number of endpoints: 3
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:   32 | type: bulk
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize:   32 | type: bulk
       2:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    8 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 5e3  ProductID: 610
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2.4:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt



Number of possible configurations: 1  Device Class: ef  VendorID: 35d1  ProductID: 164
Interfaces: 2
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2.3:1.0 [ tty path: /dev/ttyACM0 ]
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:   64 | type: interrupt


  Number of alternate settings: 1
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/3-2.3.2.3:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:   64 | type: bulk
       1:descriptor type:  5 | EP address:  1 (out) | maxPktSize:   64 | type: bulk



Number of possible configurations: 1  Device Class: 9  VendorID: 5e3  ProductID: 610
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3.2:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: bda  ProductID: 5413
Interfaces: 1
  Number of alternate settings: 2
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt

- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2.3:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: bda  ProductID: 5487
Interfaces: 1
  Number of alternate settings: 2
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt

- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-2:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    1 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 1d6b  ProductID: 2
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/3-:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    4 | type: interrupt



Number of possible configurations: 1  Device Class: 9  VendorID: 1d6b  ProductID: 3
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/2-:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    4 | type: interrupt



Number of possible configurations: 1  Device Class: 0  VendorID: a5c  ProductID: 5842
Interfaces: 2
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/1-8:1.0 | Name:  [4] "Broadcom ControlVault 3"
    Number of endpoints: 3
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  512 | type: bulk
       1:descriptor type:  5 | EP address:  1 (out) | maxPktSize:  512 | type: bulk
       2:descriptor type:  5 | EP address: 85 ( in) | maxPktSize: 1024 | type: interrupt


  Number of alternate settings: 1
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-8:1.1 | Name:  [5] "Contacted SmartCard"
    Number of endpoints: 3
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:  512 | type: bulk
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize:  512 | type: bulk
       2:descriptor type:  5 | EP address: 86 ( in) | maxPktSize: 1024 | type: interrupt



Number of possible configurations: 1  Device Class: ef  VendorID: bda  ProductID: 58fd
Interfaces: 4
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/1-6:1.0 | Name:  [5] "Integrated Webcam"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   16 | type: interrupt


  Number of alternate settings: 9
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 0

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  128 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:  512 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 1024 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 2816 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 3072 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 4864 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize: 5120 | type: iso (isoType: async, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-6:1.1
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    0 | type: iso (isoType: async, isoUsage: data)


  Number of alternate settings: 1
- [2] Interface Number: 2 | path: /sys/bus/usb/devices/1-6:1.2 | Name:  [7] "Integrated Webcam"
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 85 ( in) | maxPktSize:   16 | type: interrupt


  Number of alternate settings: 9
- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 0

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:  128 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:  256 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:  512 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:  768 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize: 1024 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize: 2624 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize: 2688 | type: iso (isoType: async, isoUsage: data)

- [3] Interface Number: 3 | path: /sys/bus/usb/devices/1-6:1.3
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 82 ( in) | maxPktSize: 4609 | type: iso (isoType: async, isoUsage: data)



Number of possible configurations: 1  Device Class: e0  VendorID: 8087  ProductID: 26
Interfaces: 2
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/1-10:1.0
    Number of endpoints: 3
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:   64 | type: interrupt
       1:descriptor type:  5 | EP address:  2 (out) | maxPktSize:   64 | type: bulk
       2:descriptor type:  5 | EP address: 82 ( in) | maxPktSize:   64 | type: bulk


  Number of alternate settings: 7
- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:    0 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:    0 | type: iso (isoType: none, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:    9 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:    9 | type: iso (isoType: none, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:   17 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   17 | type: iso (isoType: none, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:   25 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   25 | type: iso (isoType: none, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:   33 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   33 | type: iso (isoType: none, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:   49 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   49 | type: iso (isoType: none, isoUsage: data)

- [1] Interface Number: 1 | path: /sys/bus/usb/devices/1-10:1.1
    Number of endpoints: 2
       0:descriptor type:  5 | EP address:  3 (out) | maxPktSize:   63 | type: iso (isoType: none, isoUsage: data)
       1:descriptor type:  5 | EP address: 83 ( in) | maxPktSize:   63 | type: iso (isoType: none, isoUsage: data)



Number of possible configurations: 1  Device Class: 9  VendorID: 1d6b  ProductID: 2
Interfaces: 1
  Number of alternate settings: 1
- [0] Interface Number: 0 | path: /sys/bus/usb/devices/1-:1.0
    Number of endpoints: 1
       0:descriptor type:  5 | EP address: 81 ( in) | maxPktSize:    4 | type: interrupt



---- 0x1234 via string ----
command: no device
rfid: no device
reserved: no device

---- 0x1234 via interfaces ----
0: no device
1: no device
2: no device
3: no device
4: no device
5: no device
~~~
