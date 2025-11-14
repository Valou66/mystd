#include <mystat.h>

int stat(const char *pathname,struct stat* buf){
    return sys_stat(pathname,buf);
}