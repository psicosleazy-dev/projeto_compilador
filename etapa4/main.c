#include <stdio.h>
#include "stack_management.h"
#include "list.h"
extern int yyparse(void);
extern int yylex_destroy(void);
extern void initMe(void);
extern Stack* stack;
extern LISTA* lista;
void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);

int main (int argc, char **argv)
{
  initMe();
  int ret = yyparse();
  exporta(arvore);
  libera(arvore);
  delete_stack(stack);
  arvore = NULL;
  yylex_destroy();
  return ret;
}
