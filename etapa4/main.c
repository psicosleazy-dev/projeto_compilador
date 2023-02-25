#include <stdio.h>
#include "stack_management.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);
Stack* stack;

int main (int argc, char **argv)
{
  stack = create_stack();
  int ret = yyparse();
  //printf("chega aqui");
  exporta(arvore);
  print_stack(stack);
  libera(arvore);
  arvore = NULL;
  yylex_destroy();
  return ret;
}
