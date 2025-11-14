#ifndef myunistd_h
#define myunistd_h

#include <mytypes.h>
#include <mysyscall.h>

ssize_t read(int,void*,size_t);
ssize_t write(int,const void*,size_t);
unsigned int sleep(unsigned int);
int usleep(useconds_t);

pid_t fork();
pid_t getpid();
pid_t getppid();


#endif