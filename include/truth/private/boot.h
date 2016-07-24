#pragma once

#include <truth/types.h>

status_t init_cpu(void);
status_t init_interrupts(void);
status_t init_klog(void);
status_t init_memory(struct multiboot_info *mb_info);
status_t init_paging(void);
status_t init_heap(void *bootstrap, size_t size);
status_t init_boot_modules(struct multiboot_info *mb_info);
status_t init_multitasking(void);
status_t start_init(void);
