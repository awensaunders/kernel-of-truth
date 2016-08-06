#ifndef CPU_H
#define CPU_H

static inline void halt(void) {
    __asm__ volatile ("hlt");
}

#endif
