#include <stdio.h>
#include <stdlib.h>

/**
 * PSEUDO-CODIGO:
 * 
 * INTERCALA(A,p,q,r):
 *  n1 <- q - p + 1
 *  n2 <- r - q
 *  L[0..n1+1]
 *  R[0..n2+1]
 *  PARA I <- 0 ATÉ N1 FAÇA:
 *      L[I] <- A[P+I]
 *  PARA J <- 0 ATÉ N2 FAÇA:
 *      R[J] <- A[q+1+J]
 *  L[N1+1] <- R[N2+1] <- INFINITO (PARA INDICAR O FIM DO ARRAY)
 *  I <- J <- 0
 *  PARA K <- P ATÉ R FAÇA:
 *      SE L[I] <= R[J] ENTÃO
 *          A[K] <- L[I]
 *          I <- I + 1
 *      SENÃO 
 *          A[K] <- R[J]
 *          J <- J + 1 
 * 
 * MERGESORT(A, p, r)
 *  SE P < R ENTÃO
 *      Q <- (P+R)/2
 *      MERGESORT(A, P, Q)
 *      MERGESORT(A, Q+1, R)
 *      INTERCALA(A, P, Q ,R)
 */

void mergesort(int *A, int p, int r);
void mergesort2(int *A, int n);
void intercala(int *A, int p, int q, int r);
void createRandomArray(int *A, int n);
void printArray(int *A, int n);

void intercala(int* A, int p, int q, int r){
    int n1, n2, i, j;

    n1 = q - p + 1;
    n2 = r - q;

    int *L, *R;

    L = malloc(sizeof(int) * n1);
    R = malloc(sizeof(int) * n2);

    for(i=0; i < n1;i++){
        *L = *(A+p+1);    
    }

    for(j=0; j < n2;j++){
        *R = *(A+q+1+j);
    }

    i = 0;j = 0;

    for(int k = p; k <= r; k++){
        if (*(L+i) <= *(R+j)){
            *(A+k) = *(L+i);
            i++;
        } else {
            *(A+k) = *(R+i);
            j++;
        }
    }
}

void mergesort(int *A, int p, int r){
    int q;
    if(p < r){
        q = (p+r)/2;
        mergesort(A, p, q); // Left sub array
        mergesort(A, q+1, r); // right sub array
        intercala(A, p, q, r);
    }
}

void mergesort2(int *A, int n){
    createRandomArray(A, n);
    printArray(A, n);
    mergesort(A, 0, n-1);
    printArray(A,n);
};

void createRandomArray(int *A, int n){
    A = malloc(sizeof(int)*n);
    int key;
    for(int i = 0; i < n;i++){
        key = (rand() % 100);
        printf("I:%d - Key:%d\n", i, key);
        *(A+i) = key;
    }
}

void printArray(int *A, int n){
    for(int i = 0; i < n;i++){
        printf("%d ", *(A+i));
    }
    printf("\n");
}
