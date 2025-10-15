#include <mystd.h>
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

    return 0;
}

// --- point d’entrée (le système démarre ici) ---
void _start() {
    int ret = main();
    sys_exit(ret);
}

