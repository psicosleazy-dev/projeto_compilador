#include "stack_management.h"

extern int yyparse(void);
extern int yylex_destroy(void);
extern void initMe(void);
void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);
Stack* stack;
int main (int argc, char **argv)
{
  initMe();
  int ret = yyparse();
  //exporta(arvore);
  print_code(arvore);
  //libera(arvore);
  //delete_stack(stack);
  //destroi_lista(lista);
  arvore = NULL;
  yylex_destroy();
  return ret;
}
