#include <stdio.h>
#include <stdlib.h>


union Literal{
 int int_value;
 float float_value;
 char *token; // String ou char simples
};

struct valor {
    int linha;
    int natureza;
    int tamanho;
    int tipo;
    union Literal value;
    char *label;
};

typedef struct valor valor_t;

struct no {
    valor_t valor;
    struct no *proximo;
};

typedef struct no no_t;

no_t *criar_no(valor_t valor) {
    no_t *novo = (no_t *) malloc(sizeof(no_t));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

no_t *inserir_fim(no_t *head, valor_t valor) {
    no_t *novo = criar_no(valor);
    if (head == NULL) {
        head = novo;
    } else {
        no_t *atual = head;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    return head;
}

void inicializar_lista(no_t **head) {
    *head = NULL;
}

int main() {
    no_t *lista;
    inicializar_lista(&lista);

    valor_t valor1 = { 1, 1, 4, 0, 10, "label1" };
    valor_t valor2 = { 2, 2, 8, 1, 15, "label2" };
    valor_t valor3 = { 3, 1, 12, 2, 20, "label3" };

    lista = inserir_fim(lista, valor1);
    lista = inserir_fim(lista, valor2);
    lista = inserir_fim(lista, valor3);

    // percorrer a lista e imprimir os valores
    no_t *atual = lista;
    while (atual != NULL) {
        printf("Linha: %d\nNatureza: %d\nTamanho: %d\nTipo: %d\nValue: %d\nLabel: %s\n\n",
               atual->valor.linha, atual->valor.natureza, atual->valor.tamanho, atual->valor.tipo,
               atual->valor.value, atual->valor.label);
        atual = atual->proximo;
    }

    return 0;
}
