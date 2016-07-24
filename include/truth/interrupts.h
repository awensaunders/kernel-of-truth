#pragma once

#include <truth/types.h>

struct machine_state;
typedef void (interrupt_handler_t*)(struct machine_state *state);

status_t register_interrupt_handler(interrupt_handler_t handler,
        bool privileged);
