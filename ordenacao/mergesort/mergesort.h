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
void mergesort2(int *A, int n);
void intercala(int *A, int p, int q, int r);

void intercala(int* A, int p, int q, int r){
    int n1, n2, i;

    n1 = q - p + 1;
    n2 = r - q;

    int *L, *R;

    for(i=0; i < n1;i++){
        *L = *(A+p+1);    
    }

    for(i=0; i < n2;i++){
        *R = *(A+q+1+i);
    }

    for(int )
}

void mergesort2(int *A, int n){

};