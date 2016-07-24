#pragma once

#include <truth/types.h>

// Similar to malloc.
void *kmalloc(size_t bytes);

// Similar to calloc.
void *kcalloc(size_t count, size_t size);

// Similar to realloc.
void *krealloc(void *ptr, size_t bytes);

// Similar to free.
void kfree(void *mem);
