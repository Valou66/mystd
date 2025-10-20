#include <mymath.h>
#include <mystdio.h>
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
