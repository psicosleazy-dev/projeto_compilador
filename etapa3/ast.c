#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#define ARQUIVO_SAIDA "saida.dot"
extern void *arvore;

node_t* create_node(int type,char* label, valor_t value){
    node_t *ret = NULL;
    new_node = calloc(1,sizeof(node_t));
    if(new_node != NULL){
        new_node->label = strdup(label);
        new_node->number_of_children = 0;
        new_node->children = NULL;
	new_node->value = value;
    }
    return new_node;
}

char* create_leaf(valor_t value){
    return value->value.token;
}

void add_child(node_t *tree, node_t *child){
    if(tree!=NULL && child!=NULL){
        tree->number_of_children++;
        tree->children = realloc(tree->children, tree->number_of_children * sizeof(node_t*));
        tree->number_of_children[tree->number_of_children-1] = child;
    }
    else
        printf("\nErro ao adicionar filho!");
}

static void ast_print(node_t *tree){
  if (tree != NULL)
	printf("\n%p [label =\"%s\"];",tree,tree->label);
  else
     printf("\nErro print: %s recebeu parâmetro tree = %p.\n",  __FUNCTION__, tree);
}

void exporta(void *arvore){
  node_t *tree = (node_t *) arvore;
  if (tree != NULL){
    ast_print(tree);
    int i;
    for (i = 0; i < tree->number_of_children; i++)
      ast_print(tree->children[i]);
  }
  else
    printf("\nErro exporta: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  ast_print_graphviz(tree);
}

void libera(void *arvore){
  node_t *tree = (node_t *) arvore;
  if(tree!=NULL)
    for(int i=0;i<tree->number_of_children;i++)
        libera(tree->children[i]);
  free(tree->children);
  free(tree->label);
  free(tree);
  else
    printf("\nErro!");
}

void ast_print_graphviz(node_t *tree){
  FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");
  if(foutput == NULL)
    printf("\nErro: %s não pode abrir o arquivo [%s] para escrita.\n", __FUNCTION__, ARQUIVO_SAIDA);
  if (tree != NULL){
    fprintf(foutput, "digraph grafo {\n");
    _ast_print_graphviz(foutput, tree);
    fprintf(foutput, "}\n");
    fclose(foutput);
  }
  else
    printf("\nErro graphviz: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
}

static void _ast_print_graphviz (FILE *foutput, node_t *tree){
  int i;
  if (tree != NULL){
    fprintf(foutput, "  %ld [ label=\"%s\" ];\n", (long)tree, tree->label);
    for (i = 0; i < tree->number_of_children; i++){
      fprintf(foutput, "  %ld -> %ld;\n", (long)tree, (long)tree->filhos[i]);
      _ast_print_graphviz(foutput, tree->children[i]);
    }
  }
  else
    printf("\nErro graphviz: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
}
