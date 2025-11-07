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
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (i < n1 && (j >= n2 || L[i] <= R[j])) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

void mergesort(int *A, int p, int r){
    if (p < r){
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        intercala(A, p, q, r);
    }
}

void mergesort2(int *A, int n){
    createRandomArray(A, n);
    printf("Array original:\n");
    printArray(A, n);
    mergesort(A, 0, n - 1);
    printf("\nArray ordenado:\n");
    printArray(A, n);
    printf("\n");
}

void createRandomArray(int *A, int n){
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
}

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
