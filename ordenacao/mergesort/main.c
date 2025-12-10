#include <stdio.h>
#include "mergesort.h"
#include "../faux/auxiliar.h"
#include <time.h>

int main (){
    int *A;
    int n = 100;
    A = malloc(sizeof(int) * n);

    while(n < 500000){

        double t_random = time_counter(createRandomArray, mergesort2, n, A);
        double t_crescente = time_counter(createCrescentArray, mergesort2, n, A);
        double t_decrescente = time_counter(createDecrescentArray, mergesort2, n, A);        
        
        printf("random %d %.6lf\n", n, t_random);
        printf("crescente %d %.6lf\n", n, t_crescente);
        printf("decrescente %d %.6lf\n", n, t_decrescente);

        n += n;
        A = realloc(A, n * sizeof(n));
    }
    free(A);
    return 0;
}