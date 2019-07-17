#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "output.h"


int main(int argc, char *argv[]){
    
    int i,j;
    double sum=0,norm2;
    double *A=(double*)malloc(sizeof(double)*1000000);
    double *b=(double*)malloc(sizeof(double)*1000);
    double *c=(double*)malloc(sizeof(double)*1000);
    clock_t start, end;
    double cpu_time_used;
    
    b[0]=0.5;
    for(i=0;i<999;i++){
        b[i+1]=b[i]*(-1);
    }
    randomT2(A);
    
    start = clock();
    
    for(i=0;i<1000;i++)
        for(j=0;j<1000;j++)
            A[j*1000+i]=A[j*1000+i]*b[i];
            
    
    for(i=0;i<1000;i++){
        for(j=0;j<1000;j++){
            sum=A[i*1000+j]+sum;
        }
        c[i]=sum;
        sum=0;
    }
    
    for(i=0;i<1000;i++){
        sum=c[i]*c[i]+sum;
    }
    norm2=sqrt(sum);
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cpu_time_used = cpu_time_used*1000;
    
    outputT2(norm2,cpu_time_used);
    
    free(A);
    free(b);
    free(c);
}

