#include <stdio.h>
#include "quicksort.h"
#include "../faux/auxiliar.h"

double time_counter_qs(void (*generator)(int*, int), int n, int *A){
    clock_t end, ini;
    generator(A,n);
    ini = clock();
    quicksort(A,0,n-1);
    end = clock() - ini;
    return (double) end * 1000/CLOCKS_PER_SEC;
}

int main(){
    int reps = 1;
    int n = 100;
    
    while(n <= 300000){
        int* A = malloc(n * sizeof(int));
        for(int i = 0;i < reps;i++){
            double t_random = time_counter_qs(createRandomArray, n, A);
            double t_crescente = time_counter_qs(createCrescentArray, n, A);
            double t_decrescente = time_counter_qs(createDecrescentArray, n, A);

            printf("random %d %.6lf\n", n, t_random);
            printf("crescente %d %.6lf\n", n, t_crescente);
            printf("decrescente %d %.6lf\n", n, t_decrescente);
        }
        n += n;
        free(A);
    }
    return 0;
}