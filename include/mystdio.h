#ifndef mystdio_h
#define mystdio_h

//mystd.c



void put_char(char c);
void put_string(char *s);

void put_char_nb(char nb);
void put_short(short nb);
void put_int(int nb);
void put_long(long nb);
void put_float(float nb);
void put_double(double nb);
void put_longdouble(long double nb);
void put_unsigned_char_nb(unsigned char nb);
void put_unsigned_short(unsigned short nb);
void put_unsigned_int(unsigned int nb);
void put_unsigned_long(unsigned long nb);

long read_line(char *buf,unsigned long size);

void myprintf(const char *fmt,...);
void myscanf(const char *fmt,...);

#endif