#include <stdio.h>
#include "output.h"

int count(int argc, char *argv[]){
    int sum=0, i=0;
    char *p;
    for (i = 1; i < argc; i++)
    {
        for (p = argv[i]; *p != '\0'; p++)
        {
            if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
                sum += 1;
        }
    }
    return sum;
}

int main(int argc, char *argv[]){
    int sum;
    sum=count(argc, argv);
    outputT1(sum);
}

