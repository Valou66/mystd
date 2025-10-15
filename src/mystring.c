#include <mystring.h>

long str_len(const char* string){
    long len=0;

    while(string[len]!=0){
        len++;
    }
    return len;

}

char get_ascii_digit(int nb){
    if(nb >=0 && nb<=9){
        return 48+nb;
    }
    return 0;
}
