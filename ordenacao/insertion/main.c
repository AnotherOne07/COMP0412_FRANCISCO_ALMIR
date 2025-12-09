#include <stdio.h>
#include "insertion.h"
#include "../faux/auxiliar.h"
#include <time.h>

void main(){
    int *A,n = 100;
    clock_t inicial, final;

    A = malloc(n * sizeof(int));
    while(n < 200000){
        createRandomArray(A,n);
        inicial = clock();
        insertion(A,n);
        final = clock() - inicial;
        printf("%d %lf\n", n, (double)final * 1000 / CLOCKS_PER_SEC);
        n += n;
        A = realloc(A, n * sizeof(n));
    }
    free(A);
}

