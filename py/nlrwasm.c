#include "py/mpstate.h"

#include <stdlib.h>
#include "logger.h"

#if MICROPY_NLR_WASM

#undef nlr_push

__attribute__((used)) unsigned int nlr_push_tail(nlr_buf_t *nlr);

unsigned int nlr_push(nlr_buf_t *nlr) {
    // TODO: implement
    LOG_DBG("in nlr_push");
    return 0;
}

NORETURN void nlr_jump(void *val) {
    // TODO: implement
    LOG_ERR("in nlr_jump");
    // WASI micropython does not support exceptions
    exit(1);
    MP_NLR_JUMP_HEAD(val, top)
    MP_UNREACHABLE
}

#endif // MICROPY_NLR_WASM
