#include <stdio.h>

/*
    Ordenação por inserção:
    A ideia consiste em construir o vetor ordenado aos poucos, considerando um elemento inicial
    como um vetor já ordenado, então compara um elemento da lista não ordenada (à direita) com
    o elemento da lista já ordenada e insere o elemento na sua ordem correta

    PSEUDO-CÓDIGO:
    INSERTION SORT:
        LEIA A
        PARA I <- 1 ATÉ TAMANHO(A) - 1:
            CHAVE <- A[I]
            J <- I - 1
            ENQUANTO CHAVE < A[J] E J >= 0:
                A[J+1] <- A[J]
                J <- J - 1
            A[J+1] <- CHAVE

    ANÁLISE DE COMPLEXIDADE:

    INVARIANTE

    RECORRÊNCIA
 */

void insertion(int *A, int n);

void insertion(int *A, int n){
    int v[] = {5,2,4,6,1,3};
    
    for(int i = 0; i < n;i++){
        printf("%d ", v[i]);
        *(A+i) = v[i];
    }

    int key, j;
    for(int i = 1; i < n; i++){
        key = *(A+i);
        j = i - 1;
        while(key < *(A+j) && j >= 0){
            *(A+j+1) = *(A+j);
            j = j - 1;
        }
        *(A+j+1) = key;
    }

    printf("\n");
    for(int i = 0; i < n;i++){
        printf("%d ", *(A+i));
    }
}