#pragma once

// Load a relocatable elf file like a kernel module.
// * blob: The location of the elf blob in memory.
// * size: The size of the elf blob.
// Returns a memory location with the module loaded.
void *load_elf_relocatable(void *blob, size_t size);
