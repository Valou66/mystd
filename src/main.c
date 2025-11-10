#include <mystdio.h>
#include <mymath.h>
#include <mystdlib.h>



// --- ton vrai main() ---
int main() {
    //const char msg[] = "Hello from main()!\n";

    //sys_write(1, msg, 19);

    put_string(FD_PRINT,"Hello from main()\n");
    char str1[25]="Grand ";
    char str2[25]="Singe ";
    strcpy(str1,str2);
    put_string(FD_PRINT,str1);
    int t1=47;
    char t5='m';
    char t9[]="COPACOPACOPA";
    float t13=654.54784;
    double t17=654.54784;
    long t18=5897491315;
    printf("Grand singe de %d%c %s \n",t1,t5,t9);
    printf("test %f ,\n %lf \n",t13,t17);
    printf("test long %ld \n",t18);

    put_int(FD_PRINT,strcmp("pipai","pipi"));
    put_char(FD_PRINT,'\n');

    char a[128]="test1";
    char b[128]="test2\n";

    strcat(a,b);

    put_short(FD_PRINT,str_short("32767"));
    put_char(FD_PRINT,'\n');
    put_short(FD_PRINT,str_short("32769"));
    put_char(FD_PRINT,'\n');

    put_int(FD_PRINT,str_int("2147483647"));
    put_char(FD_PRINT,'\n');
    put_int(FD_PRINT,str_int("2147483649"));
    put_char(FD_PRINT,'\n');
    put_int(FD_PRINT,str_int("-2147483648"));
    put_char(FD_PRINT,'\n');

    put_long(FD_PRINT,str_long("9223372036854775807"));
    put_char(FD_PRINT,'\n');
    put_long(FD_PRINT,str_long("9223372036854775809"));
    put_char(FD_PRINT,'\n');

    put_float(FD_PRINT,str_float("1047.5497"));
    put_char(FD_PRINT,'\n');
    put_double(FD_PRINT,str_double("1047.5497"));
    put_char(FD_PRINT,'\n');

    FILE* fichier=fopen("test1.txt","w");

    const char tttt[]="nique les juifs\n";

    fwrite(tttt,1,sizeof(tttt)-1,fichier);

    fclose(fichier);

    FILE* fichier1=fopen("test2.txt","w");

    int tab[20];

    tab[0]=1;
    for(int i=1;i<20;i++){
        tab[i]=(1+i*2);
            fprintf(fichier1,"salope %d\n",tab[i]);
    }



    fclose(fichier1);
    

    
    int aaa=10,bbb=20;

    pid_t test_pid=fork();

    if(test_pid!=0){
        printf("aaa=%d\n",aaa);
    }
    else{
        printf("bbb=%d\n",bbb);
    }
    


    
    

    return 0;
}

// --- point d’entrée (le système démarre ici) ---
void _start() {
    int ret = main();
    sys_exit(ret);
    
}

