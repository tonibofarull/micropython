# This file is part of the MicroPython project, http://micropython.org/
# The MIT License (MIT)
# Copyright (c) 2022-2023 Damien P. George
#
# This is a very simple makefile that demonstrates how to build the embed port.
# All it needs to do is build all *.c files in the micropython_embed directory.
# This makefile would be replaced with your custom build system.

WASI ?= 1

CFLAGS += \
	-DLOG_LEVEL_ENABLED=0

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

SRC += $(wildcard *.c */*.c */*/*.c */*/*/*.c */*/*/*/*.c)
OBJ += $(SRC:.c=.o)

# CFLAGS += -DMICROPY_FLOAT_IMPL=MICROPY_FLOAT_IMPL_FLOAT -DULAB_MAX_DIMS=4

$(foreach module, $(wildcard $(USER_C_MODULES)/*/micropython.mk), \
	$(eval USERMOD_DIR = $(patsubst %/,%,$(dir $(module))))\
	$(info Including User C Module from $(USERMOD_DIR))\
	$(eval include $(module))\
)

BASE := $(notdir $(USER_C_MODULES))
SRC_USERMOD_EMBED := $(subst $(USER_C_MODULES),$(EMBED_DIR)/$(BASE),$(SRC_USERMOD))
SRC_USERMOD_EMBED_CXX := $(subst $(USER_C_MODULES),$(EMBED_DIR)/$(BASE),$(SRC_USERMOD_CXX))

OBJ_USERMOD += $(SRC_USERMOD_EMBED:.c=.o)
OBJ_USERMOD_CXX += $(SRC_USERMOD_EMBED_CXX:.cpp=.o)

CFLAGS += -Wall -g

INCLUDEDIR += -I.
INCLUDEDIR += -I$(EMBED_DIR)
INCLUDEDIR += -I$(EMBED_DIR)/port

CFLAGS += $(INCLUDEDIR)

LDFLAGS += $(LDFLAGS_USERMOD)

$(EMBED_DIR)/$(BASE)/%.o: $(USER_C_MODULES)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS_USERMOD) $(INCLUDEDIR) -c -o $@ $<

CFLAGS += -DMICROPY_MODULE_BUILTIN_SUBPACKAGES=1 \
	-DMICROPY_VFS_FAT=1 \
	-DMICROPY_VFS_LFS1=1 \
	-DMICROPY_VFS_LFS2=1 \
	-DMICROPY_SSL_MBEDTLS=1 \
	-DLFS1_NO_MALLOC \
	-DLFS1_NO_DEBUG \
	-DLFS1_NO_WARN \
	-DLFS1_NO_ERROR \
	-DLFS1_NO_ASSERT \
	-DLFS2_NO_MALLOC \
	-DLFS2_NO_DEBUG \
	-DLFS2_NO_WARN \
	-DLFS2_NO_ERROR \
	-DLFS2_NO_ASSERT \
	-DMICROPY_MODULE_FROZEN_MPY \
	-DMICROPY_MODULE_FROZEN_STR

$(EMBED_DIR)/$(BASE)/%.o: $(USER_C_MODULES)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS_USERMOD) $(INCLUDEDIR) -c -o $@ $<


all:
	@echo $(SRC)
	cp logger.h $(EMBED_DIR)/py/logger.h
	$(MAKE) $(PROG)

$(PROG): $(OBJ) $(OBJ_USERMOD) $(OBJ_USERMOD_CXX)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -rf build-embed
	rm -rf micropython_embed
	rm -rf $(PROG) *.o
