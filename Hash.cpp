#ifndef HASH_CPP
#define HASH_CPP

#include "cidade.cpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Tamanho do vetor
#define SIZE 16

// Vetor de ponterios do tipo nó
typedef no *hash[SIZE];

void init(hash &H) {
    for (int i = 0; i < SIZE; i++) {
        H[i] = 0;
    }
}

int inserirNovo(hash H, dataItem *d, int (*funcHash)(dataItem *)) {
    int key = funcHash(d);//Chave gerada pela função hash
    no *copy = (no*)malloc(sizeof(no));//Cópia do item que ganhou sua chave
    copy->data = *d;

    if (H[key] == 0) {//Se a hash na posição da chave for igual a 0, insere
        H[key] = copy;
        return 0;
    } else {
        no *aux = copy;
        while (aux->prox !=0){//Enquanto o copy->prox estiver cheio, ele anda até o proximo nó
            aux=aux->prox;
        }
        aux = (no*)malloc(sizeof(no));
        aux->data = copy->data;
        aux->prox = NULL;
    }
    return -1; // Erro
}

int divisao(dataItem *d) {
    return d->key % SIZE;
}

void escrever(hash H){
    for (int i = 0; i < SIZE; i++) {
        printf("P-> %d KEY-> %d\n", i, H[i]->data.key);
    }
}

#endif