# This file is part of the MicroPython project, http://micropython.org/
# The MIT License (MIT)
# Copyright (c) 2022-2023 Damien P. George
#
# This is a very simple makefile that demonstrates how to build the embed port.
# All it needs to do is build all *.c files in the micropython_embed directory.
# This makefile would be replaced with your custom build system.

WASI ?= 0

CFLAGS += \
	-DLOG_LEVEL_ENABLED=3 \
	-DMICROPY_NLR_SETJMP=0

ifeq ($(WASI),1)
CFLAGS += \
	-D_WASI_EMULATED_MMAN \
	-D_WASI_EMULATED_SIGNAL

LDFLAGS += -lwasi-emulated-mman -lwasi-emulated-signal

CC = $(CROSS_COMPILE)/opt/wasi-sdk/bin/clang
CXX = $(CROSS_COMPILE)/opt/wasi-sdk/bin/clang++
endif

EMBED_DIR = micropython_embed
PROG = main

CFLAGS += -I.
CFLAGS += -I$(EMBED_DIR)
CFLAGS += -I$(EMBED_DIR)/port
CFLAGS += -Wall -g

SRC += main.c
SRC += $(wildcard $(EMBED_DIR)/*/*.c) $(wildcard $(EMBED_DIR)/*/*/*.c)
OBJ += $(SRC:.c=.o)

all:
	cp logger.h $(EMBED_DIR)/py/logger.h
	$(MAKE) $(PROG)

$(PROG): $(OBJ)
	$(CC) -o $@ $^

clean:
	/bin/rm -f $(OBJ) $(PROG)
