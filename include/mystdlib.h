#ifndef mystdlib_h
#define mystdlib_h

#include <mytypes.h>

#define PAGE_SIZE 4096UL
#define PAGE_ALIGN_DOWN(x) ((x) & ~(PAGE_SIZE - 1))
#define PAGE_ALIGN_UP(x) (((x) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

void *mmap_alloc(size_t user_size);
void mmap_free(void *user_ptr);
void *malloc(size_t s);
void free(void *p);


#endif