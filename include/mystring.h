#ifndef mystring_h
#define mystring_h
char get_ascii_digit(int nb);


char* strcat(char* dest,const char* src);//fait
char* strchr(const char* string, int searchChar);//fait
int strcmp(const char* first,const char* second);//fait
int strcoll(const char* first,const char* second);
unsigned long strcspn(const char* string,const char* rejectedCharacters);
void strcpy(char *dest,char *src);//fait
long strlen(const char* string);//fait


#endif