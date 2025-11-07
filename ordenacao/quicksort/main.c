#include <stdio.h>
#include "quicksort.h"
#include "../faux/auxiliar.h"

int main(){
    int reps = 15;
    int begin = 10;
    int end = 50;
    int step = 5;
    int i;

    for(i = begin; i <= end; i+=step){
        int* A = malloc(i * sizeof(int));
        createRandomArray(A, i);
        printArray(A, i);
        quicksort(A,0,i-1);
        printArray(A, i);
        free(A);
        printf("\n");
    }
    return 0;
}