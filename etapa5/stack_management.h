#ifndef STACK_H
#define STACK_H

#ifndef HASH_H
#include "hash.h"
#endif

#ifndef ERROR_H
#include "errors.h"
#endif

typedef struct stack_node{
    HASH_TABLE *data;
    struct stack_node *next;
}stack_node;

typedef struct Stack{
    stack_node *head;
    int size;
}Stack;

Stack* create_stack();
void push(Stack* stack, HASH_TABLE* data);
HASH_TABLE* pop(Stack* stack);
HASH_ENT* search_stack(Stack* stack, char*);
stack_node* retrieve(Stack* stack, int level); //get something below
int empty_stack(Stack* stack);
void print_stack(Stack* stack);
void delete_stack(Stack* stack); //free everything
int retorna_end_desloc(Stack *stack, valor_t simbolo);
int escopo_global(Stack*,valor_t);
void checkTableDec(Stack*,valor_t);
void checkTableInUse(Stack*,valor_t);
int retorna_tipo_simbolo(valor_t, Stack*);
void insere_lista_na_tabela(LISTA*,Stack*);
#endif
