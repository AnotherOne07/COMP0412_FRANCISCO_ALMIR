#include <stdio.h>
#include <stdlib.h>

void createRandomArray(int *A, int n){
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
}

void createDecrescentArray(int *A, int n){
    for (int i = 0; i < n;i++){
        A[i] = i;
    }
}

void createCrescentArray(int *A, int n){
    for(int i = n; i >= 0;i++){
        A[i] = i;
    }
}

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}