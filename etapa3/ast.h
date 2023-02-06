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
#define AST_ARRAY 317
#define AST_OR 318
#define AST_AND 319
#define AST_EQ 320
#define AST_NE 321
#define AST_G 322
#define AST_L 323
#define AST_LE 324
#define AST_GE 325
#define AST_ADD 326
#define AST_SUB 327
#define AST_MINUS 328
typedef struct node{
  char* label;
  int type;
  int number_of_children;
  struct node **children;
}node_t;

typedef struct valor{
  int line;
  int type;
  char* value;
}valor_t;

node_t* create_node(int,char*);
valor_t create_value(int,int,char*);
char* create_leaf(valor_t);
void add_child(node_t*,node_t*);
void ast_print(node_t*);
void exporta(void*);
void libera(void*);
#endif
