#include <stdio.h>

/*
PSEUDOCÓDIGO
QUICKSORT(A,p,r):
    q = PARTITION(A,p,r)
    QUICKSORT(A,p,q-1)
    QUICKSORT(A,q+1,r)

PARTITION(A,p,r): (p <= r) Condição satisfeita também para o vetor vazio
    x <- A[r] (PIVÔ)
    i <- p - 1
    PARA j <- p ATÉ r - 1 FAÇA:
        SE A[j] <= x
            i = i + 1
            TROQUE(A[i], A[j])
    TROQUE(A[i+1], A[r])
    RETORNE i+1


QUICKSORT E O SUBPROBLEMA DA DIVISÃO (PARTITION):

"Rearranjar A[p..r] de modo que todos os elementos pequenos fiquem no início do vetor e todos
os elementos grandes fiquem no fim" FEOFILOFF

Ponto de partida: ESCOLHA DE UM PIVÔ

É preciso escolher x de tal modo que cada uma das duas partes do vetor rearranjado seja menor que o vetor todo.
Nosso objetivo portanto é rearranjar os elementos de A[p..r] de encontrar um índice q no interval p..r t.q.

A[p..q-1] <= A[q] < A[q+1..r]

INVARIANTES:

i. A[p..i] <= x < A[i+1..j-1],
ii. A[r] = x,
iii. i < j


 */

void quicksort(int* A, int p, int r);
int partition(int* A, int p, int r);

void quicksort(int* A, int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q+1, r);
    }
}

void swap(int* A, int i1, int i2);

int partition(int* A, int p, int r){
    int x = A[r]; // Pivô
    int i = p - 1; // Esse índice é usado para "dividir" o vetor em menor/maior
    for(int j = p; j < r; j++){
        if(A[j] <= x) { // Se for menor do que o pivô, troca com um que é maior
            i++; 
            swap(A, i, j); 
        }
    }
    swap(A, i+1, r);
    return i+1;
}

void swap(int* A, int i1, int i2){
    int aux = A[i1];
    A[i1] = A[i2];
    A[i2] = aux;
}