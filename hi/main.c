//
//  main.c
//  c
//
//  Created by Chen Miao on 09.07.19.
//  Copyright © 2019 Chen Miao. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "output.h"


int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, i;
    printf("How many numbers you want to sort?\nInput here a value form 1 to 99:");
    scanf("%d", &n);
    if(n<=0){
        printf("The number you just input is be bigger than 0 and smaller then 100!\nPlease run again!\n");
    }
    else{
    int s[n];
    for(i = 0; i < n; i++){
        printf("Input your value number %d:",i+1);
        scanf("%d", &s[i]);
    }
    qsort(s, n, sizeof(s[0]), cmp);
    printf("The result is:\n");
    outputT5(s, n);
    printf("\n");
    }
}
