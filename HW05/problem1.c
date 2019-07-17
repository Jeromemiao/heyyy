#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "omp.h"

int main(int argc, char *argv[]){
    
    int n=atoi(argv[1]), i;
    double sum=0,h,matlab=32.121040666358,diff,lang=100;
    double *XI=(double*)malloc(sizeof(double)*(n+1));
    double *FU=(double*)malloc(sizeof(double)*(n+1));
    clock_t start, end;
    double cpu_time_used;
    
    h=lang/n;
    XI[0]=0;
    for(i=0;i<n;i++)
        XI[i+1]=XI[i]+h;
    
    start = clock();
    
#pragma omp parallel for
    for(i=0;i<(n+1);i++)
        FU[i]=(exp(sin(XI[i])))*(cos(XI[i]/40));
    
#pragma omp parallel for reduction(+:sum)
    for(i=4;i<(n-3);i++){
        sum += 48*FU[i];
    }
    
    sum=sum+17*(FU[0]+FU[n])+59*(FU[1]+FU[n-1])+43*(FU[2]+FU[n-2])+49*(FU[3]+FU[n-3]);
    sum=h*sum/48;
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cpu_time_used = cpu_time_used*1000;
    
    diff=matlab-sum;
    
    printf("diff=%.15lf\n",diff);
    printf("Time=%.15lfms\n",cpu_time_used);
    
    free(XI);
    free(FU);
    
}
