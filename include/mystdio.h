#ifndef mystdio_h
#define mystdio_h

/*
Lien:

Table appel systeme:https://syscall.sh/
*/

//mystd.c
long sys_write(int fd, const char *buf, unsigned long count);
void sys_exit(int code);

void put_char(char c);
void put_string(char *s);

void put_char_nb(char nb);
void put_short(short nb);
void put_int(int nb);
void put_long(long nb);

void put_float(float nb,int p);
void put_double(double nb,int p);
void put_longdouble(long double nb,int p);

void myprintf(const char *fmt,...);



#define INT8MAX 127
#define INT16MAX 32767
#define INT32MAX 2147483647
#define INT64MAX 9223372036854775807

#define NEGINT8MAX -128
#define NEGINT16MAX -32768
#define NEGINT32MAX -2147483648
#define NEGINT64MAX -9223372036854775808

#define FLOAT_P 6

#endif