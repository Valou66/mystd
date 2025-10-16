#include <mystdio.h>
#include <mystring.h>

// --- ton vrai main() ---
int main() {
    //const char msg[] = "Hello from main()!\n";

    //sys_write(1, msg, 19);

    put_string("Hello from main()\n");
    put_string("bit\n");


    put_char_nb(INT8MAX);
    put_string("\n");

    put_char_nb(NEGINT8MAX);
    put_string("\n");
    
    put_short(INT16MAX);
    put_string("\n");

    put_short(NEGINT16MAX);
    put_string("\n");

    put_int(INT32MAX);
    put_string("\n");

    put_int(NEGINT32MAX);
    put_string("\n");

    put_long(INT64MAX);
    put_string("\n");

    put_long(NEGINT64MAX);
    put_string("\n");

    char str1[25]="Grand ";
    char str2[25]="Singe ";

    put_string(str1);
    put_string("\n");
    put_string(str2);
    put_string("\n");

    strcpy(str1,str2);

    put_string(str1);
    put_string("\n");

    float nb1=587.471f;
    double nb2=587.471L;
    long double nb3=587.471L;
    int p=6;

    put_float(nb1,p);
    put_string("\n");

    put_double(nb2,p);
    put_string("\n");

    put_longdouble(nb3,p);
    put_string("\n");

    int t1=47;
    char t5='m';
    char t9[]="COPACOPACOPA";
    

    myprintf("Grand singe de %d%c %s  %d%d%d%d,%d%d%d%d,%d%d%d%d,%d%d%d%d,\n",t1,t5,t9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5);

    return 0;
}

// --- point d’entrée (le système démarre ici) ---
void _start() {
    int ret = main();
    sys_exit(ret);
}

