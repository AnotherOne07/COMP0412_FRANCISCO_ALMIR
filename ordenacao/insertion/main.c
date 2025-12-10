#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"
#include "../faux/auxiliar.h"
#include <time.h>

double medir_tempo(void (*gerador)(int*, int), int n, int *A){
    clock_t ini,fim;
    gerador(A,n);
    // printArray(A, n);
    ini = clock();
    insertion(A,n);
    // printArray(A, n);
    fim = clock() - ini;
    return (double)fim * 1000 / CLOCKS_PER_SEC;
}

int main(){
    int *A,n = 100;

    A = malloc(n * sizeof(int));

    while(n <= 200000){
        
        double t_random = medir_tempo(createRandomArray, n, A);
        double t_crescente = medir_tempo(createCrescentArray, n, A);
        double t_decrescente = medir_tempo(createDecrescentArray, n, A);        

        printf("random %d %.6lf\n", n, t_random);
        printf("crescente %d %.6lf\n", n, t_crescente);
        printf("decrescente %d %.6lf\n", n, t_decrescente);

        n += n;
        A = realloc(A, n * sizeof(n));
    }
    free(A);
    return 0;
}

