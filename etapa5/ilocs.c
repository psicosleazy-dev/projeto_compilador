#include "ilocs.h"
#include "ast.h"
#include "hash.h"
#include "stack_management.h"
#include "list.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 3

char *gera_rotulo(void)
{
  char *label = (char *)malloc(MAX_LEN * sizeof(char));
  static int contador = 0;
  snprintf(label, 200, "L%d", contador++);
  return label;
}

/*int gera_rotulo(void){
  static int contador = 0;
  return contador++;
}*/

char *gera_temp(void)
{
  char *temp = (char *)malloc(MAX_LEN * sizeof(char));
  static int contador = 0;
  snprintf(temp, 200, "r%d", contador++);
  return temp;
}

void insere_lista_ilocs(LISTA_ILOCS **lista, ILOC inst)
{
  LISTA_ILOCS *p = (LISTA_ILOCS *)malloc(sizeof(LISTA_ILOCS));
  p->inst = inst;
  p->next = NULL;

  if (*lista == NULL)
    *lista = p;
  else
  {
    LISTA_ILOCS *aux = *lista;
    while (aux->next)
      aux = aux->next;
    aux->next = p;
  }
}

ILOC gera_inst(int tipo,char *op, char *op1, char *op2, char *res)
{
  ILOC inst;

  inst.tipo_iloc = tipo;
  if (op)
    inst.op = strdup(op);
  if (op1)
    inst.op1 = strdup(op1);
  if (op2)
    inst.op2 = strdup(op2);
  if (res)
    inst.res = strdup(res);

  return inst;
}

ILOC gera_inst_com_label(char* label,ILOC inst){
  inst.label = strdup(label);
  return inst;
}

void print_iloc(ILOC inst){
  switch(inst.tipo_iloc){
    case ILOC_ADD:
    case ILOC_SUB:
    case ILOC_MULT:
    case ILOC_DIV:
    case ILOC_DEC:
    case ILOC_OR:
    case ILOC_AND:
        printf("%s    %s, %s => %s",inst.op,inst.op1,inst.op2,inst.res);
        break;
    case ILOC_ATT:
        printf("%s    %s     => %s, %s",inst.op,inst.op1,inst.op2,inst.res);
        break;
    case ILOC_LE:
    case ILOC_LESS:
    case ILOC_EQ:
    case ILOC_GE:
    case ILOC_GREAT:
    case ILOC_DIF:
        printf("%s %s, %s    -> %s",inst.op,inst.op1,inst.op2,inst.res);
        break;
    case ILOC_LOADI:
        printf("%s %s        => %s",inst.op,inst.op1,inst.op2);
        break;
    case ILOC_BR:
        printf("%s %s        -> %s, %s",inst.op,inst.op1,inst.op2,inst.res);
        break;
    case ILOC_JUMP:
        printf("%s           -> %s",inst.op,inst.op1);
        break;
        /*case ILOC_LABEL:

    case ILOC_NOP:*/
  }
}

void print_list_ilocs(LISTA_ILOCS *l)
{
  LISTA_ILOCS *currentNode = l;
  while (currentNode != NULL)
  {
    print_iloc(currentNode->inst);
    currentNode = currentNode->next;
  }
  printf("\n");
}

void free_list(LISTA_ILOCS* l){
   LISTA_ILOCS* current,*next;

    current = l;

    while(current){
        next = current->next;
        free(current);
        current = next;
    }
}

int escopo_global(Stack *stack, valor_t s)
{
  stack_node *aux;
  aux = stack->head;
  HASH_ENT *achou;
  while (aux)
  {
    achou = ht_search(aux->data, s.value.token);
    if (achou){
      if (aux->next)
        return 0; // se a tabela nao e a ultima (escopo nao e global, é local)
      else
        return 1; // a tabela é a ultima, escopo global
    }
  }
  return 0;
}

int retorna_end_desloc(Stack *stack, valor_t simbolo)
{
  HASH_ENT *ent = NULL;
  ent = search_stack(stack, simbolo.value.token);

  if (ent)
    return ent->desloc;
  else{
    printError(ERR_UNDECLARED, simbolo.value.token, 0);
    return 0; // so pra parar encher o saco
}
}

/*
void concat_lista_ilocs(LISTA_ILOCS* l1,LISTA_ILOCS* l2){

}*/

int main(){
  LISTA_ILOCS *l = NULL;
  ILOC inst, inst2;

  inst = gera_inst(ILOC_ADD,"add","r1","r2",gera_temp());
  inst2 = gera_inst(ILOC_ADDI,"addi","r1","r2",gera_temp());
  inst2 = gera_inst_com_label("L0",inst2);

  insere_lista_ilocs(&l,inst);
  insere_lista_ilocs(&l,inst2);

  print_lista_ilocs(l);

  return 0;
}
