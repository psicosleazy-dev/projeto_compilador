#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "list.h"
#include "errors.h"

void inicia_lista(){
    lista2 = NULL;
}

void insere(valor_t valor_lexico){
    LISTA* p = (LISTA *)malloc(sizeof(LISTA));
    p->valor_lexico = valor_lexico;
    p->prox = NULL;

    if(lista2==NULL)
        lista2 = p;
    else{
        p->prox = lista2;
        lista2 = p;
    }
    printf("inseriu\n");
}

LISTA* busca(LISTA *pRecebido, valor_t valor_lexico){
    LISTA *aux, *elem = NULL;
    aux = pRecebido;
    while(aux && strcmp(aux->valor_lexico.value.token,valor_lexico.value.token)!=0)
        aux = aux->prox;
    if(aux){
        elem = aux;
        printf("achou igual");
        return elem;
    }
    else
        return NULL;
}

void init_lista_dec(){
    listadec = NULL;
}

void insere_dec(LISTA* lista){
    LISTA_DEC* p = (LISTA_DEC *)malloc(sizeof(LISTA_DEC));
    p->lista = lista;
    p->prox = NULL;

    if(listadec==NULL)
        listadec = p;
    else{
        p->prox = listadec;
        listadec = p;
    }
    printf("inseriu");
}

LISTA_DEC* busca_dec(LISTA_DEC *pRecebido, valor_t valor_lexico){
    LISTA *aux = NULL, *elem = NULL;
    LISTA_DEC *aux2 = NULL, *elem2 = NULL;
    for(aux2 = pRecebido; aux2!=NULL; aux2 = aux2->prox){
        aux = aux2->lista;
        while(aux && strcmp(aux->valor_lexico.value.token,valor_lexico.value.token)!=0)
            aux = aux->prox;
    }
    if(aux)
    {
        //elem2 = (LISTA_DEC *)malloc(sizeof(LISTA_DEC));
        elem2->lista = aux;
        elem2->tipo = aux2->tipo;
        return elem2;
    }
    else
        return NULL;
}

void print_lista(LISTA* l){
    LISTA* aux = NULL;
    for(aux = l; aux!=NULL; aux = aux->prox)
        printf("\ntoken: %s",aux->valor_lexico.value.token);
}

void print_lista_dec(LISTA_DEC* l){
    LISTA_DEC* aux = NULL;
    for(aux = l;aux!=NULL;aux = aux->prox)
        print_lista(aux->lista);
}

/*
int main(){
    valor_t v;
    v.linha = 1;
    v.natureza = NAT_FUNCTION;
    v.tamanho = 1;
    v.tipo = INT_TYPE;
    v.value.token = "v";

    printf("comecou");
    inicia_lista();
    printf("iniciou");

    init_lista_dec();
    printf("iniciou dec");
    insere(v);
    printf("inseriu!");
    insere_dec(lista2);

    print_lista_dec(listadec);

    return 0;

}
*/
