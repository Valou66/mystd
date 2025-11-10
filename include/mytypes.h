#ifndef types_h
#define types_h

typedef unsigned long size_t;
typedef long ssize_t;
typedef unsigned long uintptr_t;
typedef long time_t;
typedef unsigned int useconds_t;
typedef int pid_t;

typedef struct{
    int fd;
    char mode;
    char *buffer;
    unsigned long pos;
    unsigned long size;
}FILE;

struct mmap_header{
    unsigned long total_size;
    unsigned long user_size;
};

struct timespec{
    time_t tv_sec;
    long tv_nsec;
};

#endif