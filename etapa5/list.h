#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

union Literal{
 int int_value;
 float float_value;
 char *token; // String ou char simples
};

struct valor{
  int linha;
  int natureza;
  int tamanho;
  int tipo;
  union Literal value;
  char *label;
};

typedef struct valor valor_t; // a struct que carrega o valor lexico

typedef struct lista{
	valor_t valor_lexico;
	struct lista *prox;
}LISTA;
void inicializar_lista(LISTA**);
LISTA* insere(LISTA*,valor_t);
void print_lista(LISTA*);
void destroi_lista(LISTA*);
#endif
