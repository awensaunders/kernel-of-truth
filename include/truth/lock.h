#pragma once

/* A spin lock is a CPU lock which is not likely to be contended for long.
 * A spin lock is a simple integer -- it is 1 if locked and 0 otherwise. It
 * should only be acquired via an atomic instruction. If it cannot successfully
 * be acquired, try again in a loop.
 */
typedef int spinlock_t;

// A simple definition for initializing a spin lock.
#define SPINLOCK_INIT 0

// Acquire a spin lock.
void acquire_spinlock(spinlock_t *s);

// Release a spin lock.
int release_spinlock(spinlock_t *s);
