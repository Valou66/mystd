#include <mystdio.h>
#include <mystring.h>
#include <mysyscall.h>

// --- write system call ---

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

void myprintf(const char *fmt,...){

    put_string("entrer dans myprintf\n");

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