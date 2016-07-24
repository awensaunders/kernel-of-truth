#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum status {
    Err = 0,
    Ok = 1,
} status_t;

#define checked __attribute__((warn_unused_result))
