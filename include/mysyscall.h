#ifndef mysyscall_h
#define mysyscall_h

long sys_write(int fd, void *buf, unsigned long count);
long sys_read(int fd, void *buf, unsigned long count);
long sys_read_retry(int fd,void *buf,unsigned long count);
void sys_exit(int code);

#endif