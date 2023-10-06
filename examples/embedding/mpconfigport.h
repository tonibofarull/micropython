/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2022-2023 Damien P. George
 */

// Include common MicroPython embed configuration.
#include <port/mpconfigport_common.h>

// Use the minimal starting configuration (disables all optional features).
#define MICROPY_CONFIG_ROM_LEVEL                (MICROPY_CONFIG_ROM_LEVEL_MINIMUM)

// MicroPython configuration.
#define MICROPY_ENABLE_COMPILER                 (1)
#define MICROPY_ENABLE_GC                       (1)
#define MICROPY_PY_GC                           (1)

#define MICROPY_NLR_SETJMP                      (0)

#define MICROPY_DEBUG_VERBOSE                   (1)
#define MICROPY_DEBUG_PRINTERS                  (1)

#define MODULE_CEXAMPLE_ENABLED                 (1)

#define MICROPY_VFS                 (1)
#define MICROPY_VFS_FAT           (1)
#define MICROPY_VFS_LFS1           (1)
#define MICROPY_VFS_LFS2           (1)


#define MICROPY_MODULE_BUILTIN_SUBPACKAGES           (1)


#define LFS1_NO_MALLOC 1
#define LFS1_NO_DEBUG 1
#define LFS1_NO_WARN 1
#define LFS1_NO_ERROR 1
#define LFS1_NO_ASSERT 1
#define LFS2_NO_MALLOC 1
#define LFS2_NO_DEBUG 1
#define LFS2_NO_WARN 1
#define LFS2_NO_ERROR 1
#define LFS2_NO_ASSERT  1

#define MICROPY_FLOAT_IMPL MICROPY_FLOAT_IMPL_FLOAT
#define ULAB_MAX_DIMS 4

#define MICROPY_PY_BUILTINS_BYTEARRAY (MICROPY_CONFIG_ROM_LEVEL_AT_LEAST_CORE_FEATURES)
