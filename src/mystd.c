#include <mystdio.h>
#include <mystring.h>
#include <mysyscall.h>
#include <mymath.h>

void put_char(char c){
    sys_write(1,&c,1);
}

void put_string(char *s){
    long len=strlen(s);
    sys_write(1,s,len);
}

void put_char_nb(char nb){
    char signe=0;
    if(nb<0)signe=1;

    char data[7];
    data[6]=0;
    int i=5;

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

void put_short(short nb){
    char signe=0;
    if(nb<0)signe=1;

    char data[7];
    data[6]=0;
    int i=5;

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
    char signe=0;
    if(nb<0)signe=1;

    char data[21];
    data[20]=0;
    int i=19;

    char e;

    while(nb!=0){
        e=nb%10;
        if(e<0)e=-e;
        data[i]=get_ascii_digit(e);
        nb=nb/10;
        i--;
    }
    if(i==19){
        data[i]=get_ascii_digit(0);
    }
    if(signe==1){
        data[i]='-';
        i--;
    }

    put_string(data+i+1);
}

void put_unsigned_char_nb(unsigned char nb){

    char data[7];
    data[6]=0;
    int i=5;

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

    put_string(data+i+1);

}

void put_unsigned_short(unsigned short nb){
    char data[7];
    data[6]=0;
    int i=5;

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

    put_string(data+i+1);

}

void put_unsigned_int(unsigned int nb){
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

    put_string(data+i+1);
    
}

void put_unsigned_long(unsigned long nb){
    char data[21];
    data[20]=0;
    int i=19;

    char e;

    while(nb!=0){
        e=nb%10;
        if(e<0)e=-e;
        data[i]=get_ascii_digit(e);
        nb=nb/10;
        i--;
    }
    if(i==19){
        data[i]=get_ascii_digit(0);
    }
    put_string(data+i+1);
}


void put_float(float nb,int p){
    long entier=(int)nb;
    float frac=nb-(float)entier;
    put_long(entier);
    put_char('.');

    for(int i=0;i<p;i++){
        frac *=10.0f;
        int digit=(int)frac;
        put_char('0'+digit);
        frac-=digit;
    }
}

void put_double(double nb,int p){
    long entier=(int)nb;
    double frac=nb-(double)entier;
    put_long(entier);
    put_char('.');

    for(int i=0;i<p;i++){
        frac *=10.0f;
        int digit=(int)frac;
        put_char('0'+digit);
        frac-=digit;
    }
}

void put_longdouble(long double nb,int p){
    long entier=(int)nb;
    long double frac=nb-(long double)entier;
    put_long(entier);
    put_char('.');

    for(int i=0;i<p;i++){
        frac *=10.0f;
        int digit=(int)frac;
        put_char('0'+digit);
        frac-=digit;
    }
}

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
    i++;
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
    i++;
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
    i++;
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

void myprintf(const char *fmt,...){

   
    __builtin_va_list args;
    __builtin_va_start(args,fmt);

  
    for(int i=0;fmt[i]!='\0';i++){
        if(fmt[i]=='%'){
            i++;
            char f=fmt[i];

            switch (f){
                case 'd':{
                    int val=__builtin_va_arg(args,int);
                    put_int(val);
                    break;
                }

                case 'l':{
                    if(fmt[i+1]=='f'){
                        ++i;
                        double val;
                        val=(double)__builtin_va_arg(args,double);
                        put_double(val,FLOAT_P);
                    }
                    if(fmt[i+1]=='d'){
                        ++i;
                        long val;
                        val=(long)__builtin_va_arg(args,long);
                        put_long(val);
                    }
                    if(fmt[i+1]=='u'){
                        ++i;
                        unsigned long val;
                        val=(unsigned long)__builtin_va_arg(args,unsigned long);
                        put_long(val);
                    }
                    break;
                }

                case 's':{
                    char *s=__builtin_va_arg(args,char*);
                    put_string(s);
                    break;
                }

                case 'c':{
                    char val=(char)__builtin_va_arg(args,int);
                    put_char(val);
                    break;
                }

                case 'f':{
                    double val;
                    val=(double)__builtin_va_arg(args,double);
                    put_double(val,FLOAT_P);
                    break;
                }

                
                
            }
        }

        else{
            put_char(fmt[i]);
        }
    }
}