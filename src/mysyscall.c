#include <mysyscall.h>

long sys_read(int fd, void *buf, unsigned long count){
    long ret;

    asm volatile(
        "movq $0, %%rax\n\t"   // 0 = SYS_read
        "movq %1, %%rdi\n\t"   // fd
        "movq %2, %%rsi\n\t"   // buf
        "movq %3, %%rdx\n\t"   // count
        "syscall\n\t"
        "movq %%rax, %0\n\t"   // ret = rax
        : "=r"(ret)
        : "r"((long)fd), "r"(buf), "r"(count)
        : "rax","rdi","rsi","rdx","rcx","r11","memory"
    );
    return ret;
}

long sys_read_retry(int fd,void *buf,unsigned long count){
    long r;
    do{
        r=sys_read(fd,buf,count);
    }while(r==-4);
    return r;
}

long sys_write(int fd, void *buf, unsigned long count) {
    long ret;
    asm volatile (
        "movq $1, %%rax\n\t"   // syscall number: 1 = write
        "movq %1, %%rdi\n\t"   // arg1 = fd
        "movq %2, %%rsi\n\t"   // arg2 = buf
        "movq %3, %%rdx\n\t"   // arg3 = count
        "syscall\n\t"
        "movq %%rax, %0\n\t"   // return value
        : "=r"(ret)
        : "r"((long)fd), "r"(buf), "r"(count)
        : "rax", "rdi", "rsi", "rdx"
    );
    return ret;
}

long sys_open(const char *pathname, int flags, int mode) {
    long ret;
    __asm__ volatile (
        "movq $2, %%rax\n\t"      // 2 = SYS_open
        "movq %1, %%rdi\n\t"      // pathname
        "movq %2, %%rsi\n\t"      // flags
        "movq %3, %%rdx\n\t"      // mode
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(pathname), "r"((long)flags), "r"((long)mode)
        : "rax","rdi","rsi","rdx","rcx","r11","memory"
    );
    return ret; // fd ou code d’erreur négatif
}

long sys_close(int fd) {
    long ret;
    __asm__ volatile (
        "movq $3, %%rax\n\t"   // 3 = SYS_close
        "movq %1, %%rdi\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"((long)fd)
        : "rax","rdi","rcx","r11","memory"
    );
    return ret;
}


// --- exit system call ---
void sys_exit(int code) {
    asm volatile (
        "movq $60, %%rax\n\t"  // syscall number: 60 = exit
        "movq %0, %%rdi\n\t"   // arg1 = exit code
        "syscall\n\t"
        :
        : "r"((long)code)
        : "rax", "rdi"
    );
}