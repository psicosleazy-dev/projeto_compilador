#include <stdio.h>
#include "list.h"


LISTA *criar_no(valor_t valor) {
    LISTA *novo = (LISTA *) malloc(sizeof(LISTA));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->valor_lexico = valor;
    novo->prox = NULL;
    return novo;
}

LISTA* insere(LISTA *head, valor_t valor) {
    LISTA *novo = criar_no(valor);
    if (head == NULL) {
        head = novo;
    } else {
        LISTA *atual = head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return head;
}

void inicializar_lista(LISTA **head) {
    *head = NULL;
}

void print_lista(LISTA* l){
    LISTA* aux = NULL;
    for(aux = l; aux!=NULL; aux = aux->prox){
        printf("\ntoken: %s",aux->valor_lexico.value.token);
    }
}

/*
void destroi_lista(LISTA* l){
    LISTA* aux,*aux2;

    aux = l;

    while(aux){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    l = NULL;
}


int main(){
    valor_t v;
    v.linha = 1;
    v.natureza = 30;
    v.tamanho = 1;
    v.tipo = 30;
    v.value.token = "v";

    valor_t x;
    x.linha = 1;
    x.natureza = 30;
    x.tamanho = 1;
    x.tipo = 30;
    x.value.token = "x";

    LISTA* l;

    inicializar_lista(&l);

    l = insere(l,v);
    l = insere(l,x);

    print_lista(l);

    return 0;

}
*/