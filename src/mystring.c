#include <mystring.h>
#include <mymath.h>
#include <mystdio.h>

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

int strcmp(const char* first,const char* second){
    long len1=strlen(first);
    long len2=strlen(second);

    if(len1<len2){
        return -1;
    }
    else if(len1>len2){
        return 1;
    }

    long get_min=long_min(len1,len2);



    for(long i=0;i<get_min;i++){
        if(first[i]<second[i]){
            return -1;
        }
        else if(first[i]>second[i]){
            return 1;
        }
    }
    return 0;
}

char* strcat(char* dest,const char* src){
    char* ptdest=dest;

    while(*dest!='\0'){
        dest++;
    }

    while(*src!='\0'){
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
    return ptdest;
}

char* strchr(const char* string, int searchChar){
    char* pt=string;

    while(*pt!='\0' && *pt!=searchChar){
        pt++;
    }

    if(*pt=='\0'){
        return NULL;
    }
    else{
        return pt;
    }

}
/*
unsigned long strcspn(const char* string,const char* rejectedCharacters){
    unsigned long int res=0;
    char* pt1=string;
    char* pt2=rejectedCharacters;

    int reject=0;

    while(*pt1!='\0' && reject==0){

    }


}
*/
