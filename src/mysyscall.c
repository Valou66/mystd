#include <mysyscall.h>
#include <mystdlib.h>

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

long sys_write(int fd, const void *buf, unsigned long count) {
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

long sys_stat(const char *pathname,struct stat *buf){
    long ret;
    __asm__ volatile(
        "movq $4, %%rax\n\t"    // syscall 4: stat
        "movq %1, %%rdi\n\t"    // arg1: pathname
        "movq %2, %%rsi\n\t"    // arg2: struct stat*
        "syscall\n\t"
        "movq %%rax, %0\n\t"    // return value
        : "=r"(ret)
        : "r"(pathname), "r"(buf)
        : "rax","rdi","rsi","rcx","r11","memory"
    );
    return ret;
}

void *sys_brk(void *addr){
    long ret;
    __asm__ volatile (
        "movq $12, %%rax\n\t"      // SYS_brk = 12
        "movq %1, %%rdi\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(addr)
        : "rax", "rdi", "rcx", "r11", "memory"
    );
    return (void *) (uintptr_t) ret;
}

int sys_nanosleep(struct timespec *rqtp,struct timespec *rmtp){
    long ret;
    __asm__ volatile(
        "movq $35, %%rax\n\t"   // syscall 35 = nanosleep
        "movq %1, %%rdi\n\t"    // arg1 = req
        "movq %2, %%rsi\n\t"    // arg2 = rem (peut être NULL)
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(rqtp), "r"(rmtp)
        : "rax","rdi","rsi","rcx","r11","memory"
    );
    return ret;
}

long sys_getpid(){
    long ret;
    __asm__ volatile(
        "movq $39, %%rax\n\t"   // syscall 35 = nanosleep
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : 
        : "rax","rcx","r11","memory"
    );
    return ret;
}

long sys_getppid(){
    long ret;
    __asm__ volatile(
        "movq $110, %%rax\n\t"   // syscall 35 = nanosleep
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : 
        : "rax","rcx","r11","memory"
    );
    return ret;
}

int sys_fork(){
    long ret;
    __asm__ volatile(
        "movq $57, %%rax\n\t"   // syscall fork = 57
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        :
        : "rax","rcx","r11","memory"
    );
    return (int)ret;
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

void *sys_mmap(void *addr, unsigned long length, unsigned long prot,
               unsigned long flags, long fd, unsigned long offset)
{
    register void *rdi __asm__("rdi") = addr;
    register unsigned long rsi __asm__("rsi") = length;
    register unsigned long rdx __asm__("rdx") = prot;
    register unsigned long r10 __asm__("r10") = flags;
    register long r8  __asm__("r8")  = fd;
    register unsigned long r9  __asm__("r9")  = offset;
    register long rax __asm__("rax") = 9;  // syscall mmap

    __asm__ volatile("syscall"
                     : "+r"(rax)
                     : "r"(rdi), "r"(rsi), "r"(rdx), "r"(r10), "r"(r8), "r"(r9)
                     : "rcx", "r11", "memory");

    return (void *)rax;
}
/* syscall: munmap (11)
   int munmap(void *addr, size_t length);
*/
long sys_munmap(void *addr, unsigned long length) {
    long ret;
    __asm__ volatile (
        "movq $11, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(addr), "r"(length)
        : "rax","rdi","rsi","rcx","r11","memory"
    );
    return ret;
}