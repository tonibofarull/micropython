# This file is part of the MicroPython project, http://micropython.org/
# The MIT License (MIT)
# Copyright (c) 2022-2023 Damien P. George

# Set the location of the top of the MicroPython repository.
MICROPYTHON_TOP = ../..

CFLAGS += \
	-DMICROPY_NLR_SETJMP=0 -D__x86_64__=1 \
	-D_WASI_EMULATED_MMAN -D_WASI_EMULATED_SIGNAL
LDFLAGS += -lwasi-emulated-mman -lwasi-emulated-signal

# Include the main makefile fragment to build the MicroPython component.
include $(MICROPYTHON_TOP)/ports/embed/embed.mk
