#include <convert.h>
#include <mymath.h>
#include <mystring.h>

char str_char(char *buf){
    char res=0;
    long len=strlen(buf);
    int e;
    int signe;
    if(buf[0]=='-'){
        signe=1;
    }
    else{
        signe=0;
    }
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_int(10,len-i));
     
    }

    if(signe==1){
        res=-res;
    }
    return res;
}

short str_short(char *buf){
    short res=0;
    long len=strlen(buf);
    int e;
    int signe;
    if(buf[0]=='-'){
        signe=1;
    }
    else{
        signe=0;
    }
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_int(10,len-i));
     
    }
    if(signe==1){
        res=-res;
    }
    return res;
}

int str_int(char *buf){
    int res=0;
    long len=strlen(buf);
    int e;
    int signe;
    if(buf[0]=='-'){
        signe=1;
    }
    else{
        signe=0;
    }
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        if(signe)
            res=res-(e*pow_int(10,len-i));
        else
            res=res+(e*pow_int(10,len-i));
    }
    return res;
}

long str_long(char *buf){
    long res=0;
    long len=strlen(buf);
    int e;
    int signe;
    if(buf[0]=='-'){
        signe=1;
    }
    else{
        signe=0;
    }
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_long(10,len-i));
     
    }
    if(signe==1){
        res=-res;
    }
    return res;
}

float str_float(char *buf){
    float res=0.0;

    int i=0;
    int len_int=0;
    int len_frac=0;
    while(buf[i]!='\0' && buf[i]!='.'){
        i++;
        len_int++;
    }
    if(buf[i]!='\0')i++;
    while(buf[i]!='\0'){
        i++;
        len_frac++;
    }

    char cut[len_int+1];

    for(int j=0;j<len_int;j++){
        cut[j]=buf[j];
    }
    cut[len_int]='\0';
    long float_int=str_long(cut);


    res+=(float)float_int;

    i=len_int+1;
    int j=1;
    while(buf[i]!='\0'){
        res+=(float)((float)get_digit_ascii(buf[i])*powl(10.0,-j));
        j++;
        i++;
    }

    return res;

}

double str_double(char *buf){
    double res=0.0;

    int i=0;
    int len_int=0;
    int len_frac=0;
    while(buf[i]!='\0' && buf[i]!='.'){
        i++;
        len_int++;
    }

    if(buf[i]!='\0')i++;

    while(buf[i]!='\0'){
        i++;
        len_frac++;
    }

    char cut[len_int+1];

    for(int j=0;j<len_int;j++){
        cut[j]=buf[j];
    }
    cut[len_int]='\0';
    long float_int=str_long(cut);


    res+=(double)float_int;

    if(len_frac==0){
        return res;
    }

    i=len_int+1;
    int j=1;
    while(buf[i]!='\0'){
        res+=(double)((double)get_digit_ascii(buf[i])*powl(10.0,-j));
        j++;
        i++;
    }

    return res;

}

long double str_longdouble(char *buf){
    long double res=0.0;

    int i=0;
    int len_int=0;
    int len_frac=0;
    while(buf[i]!='\0' && buf[i]!='.'){
        i++;
        len_int++;
    }
    if(buf[i]!='\0')i++;
    while(buf[i]!='\0'){
        i++;
        len_frac++;
    }

    char cut[len_int+1];

    for(int j=0;j<len_int;j++){
        cut[j]=buf[j];
    }
    cut[len_int]='\0';
    long float_int=str_long(cut);


    res+=(long double)float_int;
    if(len_frac==0){
        return res;
    }

    i=len_int+1;
    int j=1;
    while(buf[i]!='\0'){
        res+=(long double)((long double)get_digit_ascii(buf[i])*powl(10.0,-j));
        j++;
        i++;
    }

    return res;

}

unsigned char str_unsigned_char(char *buf){
    unsigned char res=0;
    long len=strlen(buf);
    int e;
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_int(10,len-i));
     
    }
    return res;
}

unsigned short str_unsigned_short(char *buf){
    unsigned short res=0;
    long len=strlen(buf);
    int e;
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_int(10,len-i));
     
    }
    return res;
}

unsigned int str_unsigned_int(char *buf){
    unsigned int res=0;
    long len=strlen(buf);
    int e;
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_int(10,len-i));
     
    }
    return res;
}

unsigned long str_unsigned_long(char *buf){
    unsigned long res=0;
    long len=strlen(buf);
    int e;
    for(int i=0;i<len;i++){
        e=get_digit_ascii(buf[i]);
        res=res+(e*pow_long(10,len-i));
     
    }
    return res;
}