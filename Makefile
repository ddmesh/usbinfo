# Copyright (c) 2023, Stephan Enderlein. All rights reserved.#
#
# required host packages:
#     apt install libusb-dev
#


USBINFO_SRC = usbinfo.cpp usbinfo_common.c
TARGET = usbinfo

.PHONY = all clean ${TARGET}

CC = g++
STRIP = strip
CFLAGS = -Wall -O2


${TARGET}:
	@echo ">>> building $@"
	@${CC} ${CFLAGS} ${USBINFO_SRC} -o $@ -pthread -lusb-1.0
	@${STRIP} $@


clean:
	@echo ">>> cleaning ${TARGET}"
	@rm -rf ${TARGET}