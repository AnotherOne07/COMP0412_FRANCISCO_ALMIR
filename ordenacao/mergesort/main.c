#include <stdio.h>
#include "mergesort.h"
#include "../faux/auxiliar.h"
#include <time.h>

int main (){
    int *A;
    int n = 100;
    clock_t inicial, final;
    A = malloc(sizeof(int) * n);

    while(n < 500000){
        createRandomArray(A, n);
        inicial = clock();
        mergesort2(A, n);
        final = clock() - inicial;
        printf("%d %lf\n", n, (double)final * 1000 / CLOCKS_PER_SEC);
        n += n;
        A = realloc(A, n * sizeof(n));
    }
    free(A);
    return 0;
}