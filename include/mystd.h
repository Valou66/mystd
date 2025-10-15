#ifndef mystd_h
#define mystd_h

//mystd.c
long sys_write(int fd, const char *buf, unsigned long count);
void sys_exit(int code);

void put_char(char c);
void put_string(char *s);
void put_int(int nb);





#define INTMAX 2147483647


#endif