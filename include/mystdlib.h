#ifndef mystdlib_h
#define mystdlib_h

#define PAGE_SIZE 4096UL
#define PAGE_ALIGN_DOWN(x) ((x) & ~(PAGE_SIZE - 1))
#define PAGE_ALIGN_UP(x) (((x) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

typedef unsigned long size_t;
typedef long ssize_t;
typedef unsigned long uintptr_t;

struct mmap_header{
    unsigned long total_size;
    unsigned long user_size;
};

void *mmap_alloc(size_t user_size);
void mmap_free(void *user_ptr);
void *malloc(size_t s);
void free(void *p);


#endif