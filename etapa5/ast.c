#include "ast.h"
#define ARQUIVO_SAIDA "saida.dot"
extern void *arvore;

node_t* create_node(int type,char* label){
    node_t *new_node = NULL;
    new_node = calloc(1,sizeof(node_t));
    if(new_node != NULL){
        new_node->label = strdup(label);
        new_node->type = type;
        new_node->number_of_children = 0;
        new_node->children = NULL;
    }
    return new_node;
}

char* create_leaf(valor_t value){
    return value.value.token;
}

void add_child(node_t *tree, node_t *child){
    if(tree!=NULL && child!=NULL){
        tree->number_of_children++;
        tree->children = realloc(tree->children, tree->number_of_children * sizeof(node_t*));
        tree->children[tree->number_of_children-1] = child;
    }
}

static void ast_print(node_t *tree){
  if (tree != NULL){
     printf("%p [label =\"%s\"];\n",tree,tree->label);
     for (int i = 0; i < tree->number_of_children; i++)
        ast_print(tree->children[i]);
  }
}

static void _ast_print_graphviz (FILE *foutput, node_t *tree){
  int i;
  if (tree != NULL){
    for (i = 0; i < tree->number_of_children; i++){
      fprintf(foutput, "%ld -> %ld;\n", (long)tree, (long)tree->children[i]);
      _ast_print_graphviz(foutput, tree->children[i]);
    }
  }
}

static void _ast_print_graphviz2 (FILE *foutput, node_t *tree){
  int i;

  fprintf(foutput, "%ld [label=\"%s\"];\n", (long)tree, tree->label);
    for (i = 0; i < tree->number_of_children; i++){
      _ast_print_graphviz2(foutput, tree->children[i]);
    }
}

void ast_print_graphviz(node_t *tree){
  FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");
  if(foutput == NULL)
    printf("\nErro: %s não pode abrir o arquivo [%s] para escrita.\n", __FUNCTION__, ARQUIVO_SAIDA);
  //fprintf(foutput, "digraph {\nlabel=\"Ref\";\n");
  if (tree != NULL){
    _ast_print_graphviz(foutput, tree);
    _ast_print_graphviz2(foutput, tree);
    //fprintf(foutput, "}\n");
    fclose(foutput);
  }
}

void exporta(void *arvore){
  node_t *tree = (node_t *) arvore;
  ast_print(tree);
  ast_print_graphviz(tree);
}

void libera(void *arvore){
  node_t *tree = (node_t *) arvore;
  if(tree!=NULL){
    for(int i=0;i<tree->number_of_children;i++)
        libera(tree->children[i]);
    free(tree->children);
    free(tree->label);
    free_list(tree->code);
    free(tree);
  }
}

void print_code(void *arvore){
  node_t *tree = (node_t *) arvore;
  
  print_list_ilocs(tree->code);
}
