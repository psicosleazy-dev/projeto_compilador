#ifndef HASH_HEADER
#define HASH_HEADER
#define HASH_SIZE 997
#include "ast.h"

typedef struct hash_ent{
   valor_t valor_lexico; // dados acerca do simbolo
   int chave;
}HASH_ENT;

typedef struct hash_table{
    int size_table;
    HASH_ENT **items;
}HASH_TABLE;

int hashAddress(char*);
//void init_table(HASH_TABLE*);
HASH_TABLE* create_table(int);
HASH_ENT* create_item(valor_t);
void insert_item(HASH_TABLE*,valor_t);
void calcula_tamanho(valor_t);
HASH_ENT* ht_search(HASH_TABLE*,char*);
void print_table(HASH_TABLE*);
void free_item(HASH_ENT*);
void free_table(HASH_TABLE*);
#endif
