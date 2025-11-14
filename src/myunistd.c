#include <myunistd.h>

ssize_t read(int fd,void* buf,size_t count){
    return sys_read(fd,buf,count);
}
ssize_t write(int fd,const void* buf,size_t count){
    return sys_write(fd,buf,count);
}

unsigned int sleep(unsigned int seconds){
    struct timespec rqtp;

    rqtp.tv_sec=seconds;
    rqtp.tv_nsec=0;
    return sys_nanosleep(&rqtp,0);
}

int usleep(useconds_t useconds){
    struct timespec rqtp;

    rqtp.tv_nsec=0;
    rqtp.tv_sec=0;

    if(useconds<1000000){
        rqtp.tv_sec=0;
        rqtp.tv_nsec=useconds*1000;
    }

    return sys_nanosleep(&rqtp,0);
}

pid_t fork(){
    return sys_fork();   
}

pid_t getpid(){
    return sys_getpid();
}

pid_t getppid(){
    return sys_getppid();
}