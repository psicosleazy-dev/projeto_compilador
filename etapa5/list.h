#ifndef LIST_H
#define LIST_H
#include "ast.h"
typedef struct lista{
	valor_t valor_lexico;
	struct lista *prox;
}LISTA;

typedef struct lista_dec{
    int tipo;
    LISTA* lista;
    struct lista_dec *prox;
}LISTA_DEC;

LISTA* lista2; // lista de simbolos
LISTA_DEC* listadec; // lista de declaracoes de simbolos
void inicia_lista(); // inicia lista de simbolos
void insere(valor_t);
LISTA* busca(LISTA*,valor_t);
void init_lista_dec(); // inicia lista de declaração de simbolos
void insere_dec(LISTA*);
LISTA_DEC* busca_dec(LISTA_DEC*,valor_t);
void print_lista(LISTA*);
void print_lista_dec(LISTA_DEC*);
#endif
