#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandomArray(int *A, int n){
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
}

void createDecrescentArray(int *A, int n){
    int j = n - 1;
    for (int i = 0; i < n; i++){
        A[i] = j;
        j--;
    }
}

void createCrescentArray(int *A, int n){
    for(int i = 0; i < n;i++){
        A[i] = i;
    }
}

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

double time_counter(
    void (*generator)(int*, int),
    void (*ordenator)(int*, int),
    int n, int *A
){
    clock_t ini,end;
    generator(A, n);
    ini = clock();
    ordenator(A, n);
    end = clock() - ini;
    return (double)end * 1000/ CLOCKS_PER_SEC;
}