#include <stdio.h>
#include "mergesort.h"

int main (){
    int *A;
    int n = 10;
    A = malloc(sizeof(int) * n);
    mergesort2(A, n);
    free(A);
    return 0;
}