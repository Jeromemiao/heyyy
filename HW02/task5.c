#include <stdio.h>
#include <stdlib.h>
#include "output.h"


int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]){

    int n=atoi(argv[1]), i;
    int *ids=(int*)malloc(sizeof(int)*n);
    if(n<=0 || n>99 || argc!=2){
        printf("The number you just input is be bigger than 0 and smaller then 100!\nPlease run again!\n");
        exit(1);
    }
    else{
    for(i = 0; i < n; i++){
        printf("Input your value number %d:",i+1);
        scanf("%d", &ids[i]);
    }
    qsort(ids, n, sizeof(ids[0]), cmp);
    printf("The result is:\n");
    outputT5(ids, n);
    printf("\n");
    free(ids);
    }
}

