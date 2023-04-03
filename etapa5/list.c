#include "list.h"

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
}

void print_lista(LISTA* l){
    LISTA* aux = NULL;
    for(aux = l; aux!=NULL; aux = aux->prox)
        printf("\ntoken: %s",aux->valor_lexico.value.token);
}

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
