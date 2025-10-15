#include <mystd.h>
#include <mystring.h>

// --- write system call ---
long sys_write(int fd, const char *buf, unsigned long count) {
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

void put_string(char *s){
    long len=str_len(s);
    sys_write(1,s,len);
}

void put_int(int nb){
    int signe=0;
    if(nb<0) signe=1;

    char data[12];
    data[11]=0;
    int i=10;

    char e;

    while(nb!=0){
        e=nb%10;
        if(e<0)e=-e;
        data[i]=get_ascii_digit(e);
        nb=nb/10;
        i--;
    }

    if(i==10){
        data[i]=get_ascii_digit(0);
        i--;
    }
    
    if(signe==1){
        data[i]='-';
        i--;
    }

    put_string(data+i+1);
    
}

void put_long(long nb){
    int signe=0;
    if(signe)

    char data[21];
}
