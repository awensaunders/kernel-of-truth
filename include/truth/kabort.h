#pragma once

// Log a message and kernel panic.
void kabort_msg(char* string, ...);

// Kernel panic.
void kabort(void);
