#ifndef _ARVORE_H_
#define _ARVORE_H_
#define AST_LIT_INT 300
#define AST_INIT 301
#define AST_ID 302
#define AST_INDEX 303
#define AST_OR 304
#define AST_AND 305
#define AST_MOD 306
#define AST_NOT 307
#define AST_NEG 308
#define AST_CIRC 309
#define AST_CALL 310
#define AST_FUNC 311
#define AST_ATT 312
#define AST_RET 313
#define AST_IF 314
#define AST_WHILE 315
#define AST_LIT_FLOAT 316
#define AST_ARR 317
#define AST_EQ 320
#define AST_NE 321
#define AST_G 322
#define AST_L 323
#define AST_LE 324
#define AST_GE 325
#define AST_ADD 326
#define AST_SUB 327
#define AST_MINUS 328
#define AST_LIT_TRUE 329
#define AST_LIT_FALSE 330
#define AST_MUL 331
#define AST_DIV 332
#include <stdio.h>
#include "ilocs.h"

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
};

typedef struct valor valor_t;

struct node{
  char *label;
  int type;
  int datatype;
  LISTA_ILOCS* code;
  char *temp;
  int number_of_children;
  struct node **children;
};

typedef struct node node_t;

char* create_leaf(valor_t);
node_t* create_node(int,char*);
void add_child(node_t*,node_t*);
static void ast_print(node_t*);
static void _ast_print_graphviz(FILE*, node_t*);
static void _ast_print_graphviz2(FILE*, node_t*);
void exporta(void*);
void libera(void*);
#endif
