#ifndef LIST_H
#define LIST_H

#ifndef _ARVORE_H_
#include "ast.h"
#endif

typedef struct lista{
	valor_t valor_lexico;
	struct lista *prox;
}LISTA;

LISTA* lista2; // lista de simbolos
void inicia_lista(); // inicia lista de simbolos
void insere(valor_t);
void print_lista(LISTA*);
void destroi_lista(LISTA*);
#endif
