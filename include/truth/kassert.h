#pragma once

#include <truth/kabort.h>
#include <truth/klog.h>

// An assertion macro. Log the location of the failure and kernel panic.
#define kassert(value) if (!(value)) { \
    klogf("Assertion failed: (%s) function %s, file %s, line %d.", \
    #value, __FUNCTION__, __FILE__, __LINE__); \
    kabort(); \
}
