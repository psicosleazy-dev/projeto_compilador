#ifndef HASH_HEADER
#define HASH_HEADER
#define HASH_SIZE 997

#ifndef _ARVORE_H_
#include "ast.h"
#endif

#include "errors.h"

typedef struct hash_ent{
   valor_t valor_lexico; // dados acerca do simbolo
   int chave;
   int desloc;
}HASH_ENT;

typedef struct hash_table{
    int size_table;
    HASH_ENT **items;
}HASH_TABLE;

int hashAddress(char*);
HASH_TABLE* create_table(int);
HASH_ENT* create_item(valor_t);
void insert_item(HASH_TABLE*,valor_t);
void calcula_tamanho(valor_t);
HASH_ENT* ht_search(HASH_TABLE*,char*);
void print_table(HASH_TABLE*);
void free_item(HASH_ENT*);
void free_table(HASH_TABLE*);
#endif
