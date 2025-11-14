#ifndef mysyscall_h
#define mysyscall_h

#include <mytypes.h>
#include <mystat.h>

/*
Lien:

Table appel systeme:https://syscall.sh/
*/



//syscall 0
long sys_read(int fd, void *buf, unsigned long count);
long sys_read_retry(int fd,void *buf,unsigned long count);

//syscall 1
long sys_write(int fd, const void *buf, unsigned long count);

//syscall2
long sys_open(const char *filename,int flags,int mode);

//syscall3
long sys_close(int fd);

//syscall4
long sys_stat(const char *pathname,struct stat *buf);

//syscall12
void *sys_brk(void *addr);

//syscall35
int sys_nanosleep(struct timespec *rqtp,struct timespec *rmtp);

//syscall39
long sys_getpid();


//syscall 57

int sys_fork();

//syscall 60
void sys_exit(int code);

void *sys_mmap(void *addr, unsigned long length, unsigned long prot,
                      unsigned long flags, long fd, unsigned long offset);


long sys_munmap(void *addr, unsigned long length);

//syscall110

long sys_getppid();


#endif
