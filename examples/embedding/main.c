/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2022-2023 Damien P. George
 */

#include <stdio.h>
#include <stdarg.h>

#include "port/micropython_embed.h"
#include "py/gc.h"
#include "logger.h"

int DEBUG_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = vprintf(fmt, ap);
    va_end(ap);
    return ret;
}

static const char *code1 =
"print('hi')\n"
"dummy_data = bytes(2000)\n"
;

static const char *code2 =
"print('bye')"
;

// This array is the MicroPython GC heap.
static char heap[ 8 * 1024 ] = { 0 };

int main() {
    mp_embed_init(&heap[0], sizeof(heap));
    for (int i = 0; i < 10; ++i) {
        mp_embed_exec_str(code1);
        mp_embed_exec_str(code2);
        LOG_INFO("###############################################################");
        gc_dump_info(&mp_plat_print);
    }
    mp_embed_deinit();
    return 0;
}
