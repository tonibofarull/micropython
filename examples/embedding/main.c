/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2022-2023 Damien P. George
 */

#include <stdio.h>
#include "port/micropython_embed.h"

// This is example 1 script, which will be compiled and executed.
static const char *example_1 =
"a = [2**x for x in range(10)]\n"
"print(a)\n"
"\n"
"def fib(n):\n"
"    if n <= 0:\n"
"        return 0\n"
"    if n <= 2:\n"
"        return 1\n"
"    return fib(n-1)+fib(n-2)\n"
"print(fib(5))\n"
"print(fib(19))\n"
"class A:\n"
"    def __init__(self):\n"
"        self.x = fib(19)\n"
"a = A()\n"
"print(a.x+1)"
;

// This array is the MicroPython GC heap.
static char heap[8 * 1024];

int main() {
    // Initialise MicroPython.
    // printf("here\n"); fflush(stdout);
    mp_embed_init(&heap[0], sizeof(heap));
    // printf("here\n"); fflush(stdout);
    // Run the example scripts (they will be compiled first).
    mp_embed_exec_str(example_1);
    // printf("here\n"); fflush(stdout);
    // mp_embed_exec_str(example_2);

    // Deinitialise MicroPython.
    mp_embed_deinit();

    return 0;
}
