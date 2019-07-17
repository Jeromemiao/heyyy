#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int main(int argc, char *argv[]) {
    int i,n=atoi(argv[1]);
    for (i=1;i<=n;i++){
        outputT2(i);
    }
}

