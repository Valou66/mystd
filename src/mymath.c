#include <mymath.h>
#include <mystdio.h>
#include <macro.h>
int int_min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

long long_min(long a,long b){
    if(a<b){
        return a;
    }
    return b;
}

int pow_int(int x,int n){
    if(n==0){
        return 1;
    }
    int res=1;
    for(int i=1;i<n;i++){
        res=res*x;
    }
    return res;
}

long pow_long(long x,long n){
    if(n==0){
        return 1;
    }
    long res=1;
    for(long i=1;i<n;i++){
        res=res*x;
    }
    return res;
}

float powf(float x,int n){
    float res=1.0f;
    if(n==0){
        return res;
    }

    else if(n>0){
        for(long i=1;i<n;i++){
            res=res*x;
        }
    }

    else{
        n=-n;
        for(long i=1;i<n;i++){
            res=res/x;
        }
    }
        
    return res;
}

double powl(double x,int n){
    double res=1.0f;
    if(n==0){
        return res;
    }

    else if(n>0){
        for(long i=1;i<n;i++){
            res=res*x;
        }
    }

    else{
        n=-n;
        for(long i=0;i<n;i++){
            
            res=res/x;
        }
    }
        

    return res;
}

float absf(float nb){
    if(nb<0.0) return -nb;
    return nb;
}

float sqrtf(float nb){
    if(nb==0.0)return 0.0f;

    float result=nb;

    for(int i=0;i<SQRT_P;i++){
        result=(1.0/2.0)*(result+nb/result);
    }

    return result;
}

double sqrtl(double nb){
    if(nb==0.0)return 0.0;

    double result=nb;

    for(int i=0;i<SQRT_P;i++){
        result=(1.0/2.0)*(result+nb/result);
    }

    return result;
}

double ln(double x){
    if(x<=0){
        printf("ln non definit");
        return 0.0;
    }

    int k=0;
    while(x>2.0){
        x/=EXP;
        k++;
    }

    double y=x-1;
    double term=y;
    double result=y;
    int n;

    for(n=2;n<LN_P;n++){
        term*=-y*(n-1)/n;
        result+=term;
    }

    result +=k;
    return result;
}