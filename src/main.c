#include <mystdio.h>
#include <mystring.h>
#include <mysyscall.h>

// --- ton vrai main() ---
int main() {
    //const char msg[] = "Hello from main()!\n";

    //sys_write(1, msg, 19);

    put_string("Hello from main()\n");
    char str1[25]="Grand ";
    char str2[25]="Singe ";
    strcpy(str1,str2);
    put_string(str1);
    int t1=47;
    char t5='m';
    char t9[]="COPACOPACOPA";
    float t13=654.54784;
    double t17=654.54784;
    long t18=5897491315;
    myprintf("Grand singe de %d%c %s \n",t1,t5,t9);
    myprintf("test %f ,\n %lf \n",t13,t17);
    myprintf("test long %ld \n",t18);

    // long testread;
    // put_string("entre stp\n");
    // sys_read(0,&testread,sizeof(long));

    // put_long(testread);

    put_int(strcmp("pipai","pipi"));
    put_char('\n');

    char a[128]="test1";
    char b[128]="test2\n";

    strcat(a,b);

    put_string(a);
    return 0;
}

// --- point d’entrée (le système démarre ici) ---
void _start() {
    int ret = main();
    sys_exit(ret);
}

