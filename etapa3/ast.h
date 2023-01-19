#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct node{
  char* label;
  int type;
  int number_of_children;
  struct node **children;
}node_t;

typedef struct valor_lexico{
  int line;
  int type;
  char* value;
}valor_t;

node_t* create_node(int,char*);
valor_t create_value(int,int,char*);
void add_child(node_t*,node_t*);


#endif
