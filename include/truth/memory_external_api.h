#pragma once

typedef page_t uintptr_t;
typedef phys_addr_t uintptr_t;
typedef page_directory_t phys_addr_t;

void *get_page_set(size_t);
void put_page_set(void*);

void *get_page_set_backed_by(phys_addr_t, size_t);

page_directory_t get_page_directory(void);
void *insert_region_page_directory(page_directory_t, size_t);
