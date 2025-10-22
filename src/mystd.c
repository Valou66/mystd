#include <mystdio.h>

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


void put_float(float nb){
    long entier=(int)nb;
    float frac=nb-(float)entier;
    put_long(entier);
    put_char('.');

    for(int i=0;i<FLOAT_P;i++){
        frac *=10.0f;
        int digit=(int)frac;
        put_char('0'+digit);
        frac-=digit;
    }
}

void put_double(double nb){
    long entier=(int)nb;
    double frac=nb-(double)entier;
    put_long(entier);
    put_char('.');

    for(int i=0;i<FLOAT_P;i++){
        frac *=10.0f;
        int digit=(int)frac;
        put_char('0'+digit);
        frac-=digit;
    }
}

void put_longdouble(long double nb){
    long entier=(int)nb;
    long double frac=nb-(long double)entier;
    put_long(entier);
    put_char('.');

    for(int i=0;i<FLOAT_P;i++){
        frac *=10.0f;
        int digit=(int)frac;
        put_char('0'+digit);
        frac-=digit;
    }
}

long read_line(char* buf,unsigned long size){
    long n=sys_read(0,buf,size-1);
    if(n<=0)return n;

    for(long i=0;i<n;i++){
        if(buf[i]=='\n' || buf[i]=='\r'){
            buf[i]='\0';
            return i;
        }
    }

    buf[n]='\0';
    return n;
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
                        put_double(val);
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
                    put_double(val);
                    break;
                }

                
                
            }
        }

        else{
            put_char(fmt[i]);
        }
    }
}

void myscanf(const char *fmt,...){
    __builtin_va_list args;
    __builtin_va_start(args,fmt);

    char buf[INPUT_BUF_SIZE];

    for(int i=0;fmt[i]!='\0';i++){
        i++;
        char f=fmt[i];

        switch(f){
            case 'c':{
                read_line(buf,sizeof(buf));
                char *p=__builtin_va_arg(args,char*);
                *p=buf[0];
                break;
            }

            case 'd':{
                read_line(buf,sizeof(buf));
                int*p=__builtin_va_arg(args,int*);
                *p=str_int(buf);
                break;
            }

            case 'l':{
                char n=fmt[i+1];
                switch(n){
                    case 'd':{
                        read_line(buf,sizeof(buf));
                        long *p=__builtin_va_arg(args,long*);
                        *p=str_long(buf);
                        i++;
                        break;
                    }
                    case 'f':{
                        read_line(buf,sizeof(buf));
                        double *p=__builtin_va_arg(args,double*);
                        *p=str_double(buf);
                        i++;
                        break;
                    }
                    case 'u':{
                        read_line(buf,sizeof(buf));
                        unsigned long *p=__builtin_va_arg(args,unsigned long*);
                        *p=str_unsigned_long(buf);
                        i++;
                        break;
                    }
                }
                break;
            }

            case 'f':{
                read_line(buf,sizeof(buf));
                float*p=__builtin_va_arg(args,float*);
                *p=str_float(buf);
                break;
            }

            case 'u':{
                read_line(buf,sizeof(buf));
                unsigned int*p=__builtin_va_arg(args,unsigned int*);
                *p=str_unsigned_int(buf);
                break;
            }

            case 's':{
                read_line(buf,sizeof(buf));
                char *p=__builtin_va_arg(args,char*);
                int j=0;
                while(buf[j]!='\0'){
                    p[j]=buf[j];
                    j++;
                }
                p[j]='\0';
                break;
            }
        }
    }
    __builtin_va_end(args);
}

FILE *fopen(const char *nom, const char *mode){
    int flags=0;
    int perms=0644;

    if (mode[0] == 'r') {
        if (mode[1] == '+') flags = O_RDWR;
        else flags = O_RDONLY;
    } else if (mode[0] == 'w') {
        if (mode[1] == '+') flags = O_RDWR | O_CREAT | O_TRUNC;
        else flags = O_WRONLY | O_CREAT | O_TRUNC;
    } else if (mode[0] == 'a') {
        if (mode[1] == '+') flags = O_RDWR | O_CREAT | O_APPEND;
        else flags = O_WRONLY | O_CREAT | O_APPEND;
    } else {
        return 0; // mode invalide
    }

    int fd = sys_open(nom, flags, perms);
    if (fd < 0) return 0; // erreur d'ouverture

    // allocation de la structure
    FILE *f = (FILE*) malloc(sizeof(FILE));
    if (!f) {
        sys_close(fd);
        return 0;
    }

    f->fd = fd;
    f->mode = mode[0];
    f->buffer = 0;
    f->pos = 0;
    f->size = 0;

    return f;
}

int fclose(FILE *f){
    if(!f) return -1;
    int ret=sys_close(f->fd);
    free(f);
    return ret;
}