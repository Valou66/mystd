#ifndef mysyscall_h
#define mysyscall_h

/*
Lien:

Table appel systeme:https://syscall.sh/
*/

//syscall 0
long sys_read(int fd, void *buf, unsigned long count);
long sys_read_retry(int fd,void *buf,unsigned long count);

//syscall 1
long sys_write(int fd, void *buf, unsigned long count);

//syscall2
long sys_open(const char *filename,int flags,int mode);

long sys_close(int fd);

//syscall12
void *sys_brk(void *addr);

//syscall 60
void sys_exit(int code);

void *sys_mmap(void *addr, unsigned long length, unsigned long prot,
                      unsigned long flags, long fd, unsigned long offset);


long sys_munmap(void *addr, unsigned long length);
#endif
