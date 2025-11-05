#include <stdio.h>

/*
    Ordenação por inserção:
    A ideia consiste em comparar sequencialmente o elemento do vetor com o seu vizinho a direita
    de modo que se x < y, então faz a troca, continua esse processo até que a condicional falhe
    uma vez que encontre um número maior, retorna até a primeira posição do vetor e compara com
    o índice onde a condicional falhou, realiza a troca e anda 1 índice, e repete o mesmo 
    processo novamente

    PSEUDO-CÓDIGO:
    INSERTION SORT:
        LEIA A
        PARA I -> 0 ATÉ TAMANHO(A) - 1:
            J -> I + 1
            CHAVE -> A[0]
            ENQUANTO CHAVE < A[J] E J < TAMANHO(A):
                TROCA(A, J, J-1)
                J < J + 1


 */

void swap(int *A, int i1, int i2);
void insertion(int *A, int n);

void insertion(int *A, int n){

}