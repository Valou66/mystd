#include <mystring.h>

char get_ascii_digit(int nb){
    if(nb >=0 && nb<=9){
        return 48+nb;
    }
    return 0;
}

long strlen(const char* string){
    long len=0;

    while(string[len]!=0){
        len++;
    }
    return len;
}

void strcpy(char* dest, char* src){
    char *ptr1=dest;
    while(*ptr1!=0){
        ptr1++;
    }

    char *ptr2=src;

    while(*ptr2!=0){
        *ptr1=*ptr2;
        ptr1++;
        ptr2++;
    }
}
