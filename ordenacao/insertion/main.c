#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"
#include "../faux/auxiliar.h"
#include <time.h>

int main(){
    int *A,n = 100;

    A = malloc(n * sizeof(int));

    while(n <= 200000){
        
        double t_random = time_counter(createRandomArray, insertion, n, A);
        double t_crescente = time_counter(createCrescentArray, insertion, n, A);
        double t_decrescente = time_counter(createDecrescentArray, insertion, n, A);        

        printf("random %d %.6lf\n", n, t_random);
        printf("crescente %d %.6lf\n", n, t_crescente);
        printf("decrescente %d %.6lf\n", n, t_decrescente);

        n += n;
        A = realloc(A, n * sizeof(n));
    }
    free(A);
    return 0;
}

