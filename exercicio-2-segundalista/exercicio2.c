#include <stdio.h>
#include <stdlib.h>
struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
}; 
typedef struct arv Arv;

Arv* arv_cria(char c) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

Arv* popula_arvore() {
    Arv* a = arv_cria('a');
    a->esq = arv_cria('b');
    a->esq->esq = arv_cria('e');
    a->esq->esq->esq = arv_cria('k');
    a->esq->esq->dir = arv_cria('f');
    a->esq->esq->esq->dir = arv_cria('l');

    a->esq->dir = arv_cria('c');
    a->esq->dir->esq = arv_cria('g');
    a->esq->dir->dir = arv_cria('d');
    a->esq->dir->dir->esq = arv_cria('h');
    a->esq->dir->dir->esq->esq = arv_cria('m');
    a->esq->dir->dir->esq->dir = arv_cria('i');
    a->esq->dir->dir->esq->dir->dir = arv_cria('j');

    return a;

}

void imprime_preordem(Arv* a) {
    if(a != NULL) {
        printf("%c", a->info);
        imprime_preordem(a->esq);
        imprime_preordem(a->dir);
    }
}

void imprime_posordem(Arv* a) {
    if(a != NULL) {
        printf("%c", a->info);
        imprime_posordem(a->dir);
        imprime_posordem(a->esq);
    }
}

void imprime_equilibrado(Arv* a) {
    if(a != NULL) {
        imprime_equilibrado(a->esq);
        printf("%c", a->info);
        imprime_equilibrado(a->dir);
    }
}



int main() {
    Arv* a = popula_arvore();
    printf("Pos ordem:");
    imprime_posordem(a);
    printf("\nPre ordem:");
    imprime_preordem(a);
    printf("\nEm ordem:");
    imprime_equilibrado(a);

}