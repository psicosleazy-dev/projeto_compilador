#include "hash.h"
#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashAddress(char *text){
    int address = 1;

    unsigned long i = 0;
    for (int j = 0; text[j]; j++)
        i += text[j];

    //printf("chegou ate aqui");

    return i % HASH_SIZE;
}

HASH_ENT* create_item(valor_t value){
    // Creates a pointer to a new HashTable item.
    HASH_ENT* item = (HASH_ENT*) malloc(sizeof(HASH_ENT));
    int chave = hashAddress(value.value.token);
    item->chave = chave;
    item->valor_lexico = value;
    return item;
}

void insert_item(HASH_TABLE* table, valor_t novo_simbolo)
{
    // Creates the item.
    HASH_ENT* item = create_item(novo_simbolo);

// Computes the index.
    int index = hashAddress(novo_simbolo.value.token);

    HASH_ENT* current_item; /* = (HASH_ENT*) malloc(sizeof(HASH_ENT));*/
    current_item = table->items[index];

    if (current_item == NULL)
        table->items[index] = item;
}

void init_table(HASH_TABLE* table)
{
    // Creates a new HashTable.
    table = (HASH_TABLE*) malloc(sizeof(HASH_TABLE));
    table->size_table = HASH_SIZE;
    table->items = (HASH_ENT**) calloc(table->size_table, sizeof(HASH_ENT*));

    for (int i = 0; i < table->size_table; i++)
        table->items[i] = NULL;


}

/*
void free_item(HASH_ENT* item)
{
    // Frees an item.
    free(item->chave);
    free(item->valor_lexico);
    free(item);
}*/

void free_table(HASH_TABLE* table)
{
    // Frees the table.
    for (int i = 0; i < table->size_table; i++)
    {
        HASH_ENT* item = table->items[i];

        if (item != NULL)
            free(item);
    }

    free(table->items);
    free(table);
}

void print_table(HASH_TABLE* table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < table->size_table; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%d, Value:%s\n", i, table->items[i]->chave, table->items[i]->valor_lexico.value.token);
        }
    }

    printf("-------------------\n\n");
}

HASH_ENT* ht_search(HASH_TABLE* table, char* token)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.

    int index = hashAddress(token);

    HASH_ENT* item = table->items[index];

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->valor_lexico.value.token, token) == 0)
            return item;
    }

    return NULL;
}

HASH_TABLE* create_table(int size)
{
    // Creates a new HashTable.
    HASH_TABLE* table = (HASH_TABLE*) malloc(sizeof(HASH_TABLE));
    table->size_table = size;
    table->items = (HASH_ENT**) calloc(table->size_table, sizeof(HASH_ENT*));

    for (int i = 0; i < table->size_table; i++)
        table->items[i] = NULL;
    printf("criou");
    return table;
}

void calcula_tamanho(valor_t valor_lexico){
	switch(valor_lexico.tipo){
		case TK_LIT_FLOAT:
			valor_lexico.tamanho = 8;
			break;
		case TK_LIT_INT:
			valor_lexico.tamanho = 4;
			break;
		case TK_LIT_CHAR:
		case TK_LIT_TRUE:
		case TK_LIT_FALSE:
			valor_lexico.tamanho = 1;
			break;
	}
}
/*
int main(){
    valor_t value;

    value.linha = 2;
    value.natureza = NAT_ARRAY;
    value.tamanho = 1;
    value.tipo = INT_TYPE;
    value.value.token = "valeu";

    char *nome;

    HASH_TABLE* table = create_table(HASH_SIZE);
    HASH_ENT* res;

    init_table(table);

    insert_item(table,value);
    //printf("foi aqui");

    print_table(table);

    printf("\nEntre com um nome para pesquisar na tabela: \n");
    scanf("%s",nome);

    res = ht_search(table,nome);


    if(res)
        printf("\nencontrado nome %s",res->valor_lexico.value.token);
    else
        printf("\nnome nao encontrado");


    return 0;
}*/
