#ifndef types_h
#define types_h

typedef unsigned long size_t;
typedef unsigned long uintptr_t;
typedef unsigned long ino_t;
typedef unsigned long dev_t;
typedef long ssize_t;
typedef long time_t;
typedef long off_t;
typedef long int blksize_t;
typedef long int blkcnt_t;
typedef unsigned int useconds_t;
typedef unsigned int mode_t;
typedef unsigned int nlink_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;
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