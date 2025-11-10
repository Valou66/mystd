#ifndef mystdio_h
#define mystdio_h

#include <mystring.h>
#include <myunistd.h>
#include <convert.h>
#include <macro.h>
#include <mytypes.h>





FILE *fopen(const char *nom, const char *mode);
int fclose(FILE *f);

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
void fprintf(FILE *stream, const char *fmt, ...);

void put_char(int fd,char c);
void put_string(int fd,char *s);
void put_char_nb(int fd,char nb);
void put_short(int fd,short nb);
void put_int(int fd,int nb);
void put_long(int fd,long nb);
void put_float(int fd,float nb);
void put_double(int fd,double nb);
void put_longdouble(int fd,long double nb);
void put_unsigned_char_nb(int fd,unsigned char nb);
void put_unsigned_short(int fd,unsigned short nb);
void put_unsigned_int(int fd,unsigned int nb);
void put_unsigned_long(int fd,unsigned long nb);

long read_line(char *buf,unsigned long size);

void printf(const char *fmt,...);
void scanf(const char *fmt,...);



#endif