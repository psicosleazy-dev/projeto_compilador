#include <stdio.h>
#include "ilocs.h"

void insere_lista_ilocs(LISTA_ILOCS **lista, ILOC inst)
{
  LISTA_ILOCS *p = (LISTA_ILOCS *)malloc(sizeof(LISTA_ILOCS));
  p->inst = inst;
  p->next = NULL;

  if (*lista == NULL){
    *lista = p;
  }
  else
  {
    LISTA_ILOCS *aux = *lista;
    while (aux->next)
      aux = aux->next;
    aux->next = p;
  }
}

ILOC gera_inst(int tipo, char *op, char *op1, char *op2, char *res)
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

ILOC gera_inst_com_label(char *label, ILOC inst)
{
  inst.label = strdup(label);
  inst.tipo_iloc = ILOC_LABEL;
  return inst;
}

void print_iloc(ILOC inst)
{
  FILE *saida = fopen("saida", "a");
  if (saida)
  {
    switch (inst.tipo_iloc)
    {
    case ILOC_ADD:
    case ILOC_ADDI:
    case ILOC_SUB:
    case ILOC_SUBI:
    case ILOC_MULT:
    case ILOC_MULTI:
    case ILOC_DIV:
    case ILOC_DIVI:
    case ILOC_DEC:
    case ILOC_OR:
    case ILOC_AND:
      fprintf(saida, "\n%s    %s, %s => %s", inst.op, inst.op1, inst.op2, inst.res);
      printf("\n%s    %s, %s => %s", inst.op, inst.op1, inst.op2, inst.res);
      break;
    case ILOC_ATT:
      fprintf(saida, "\n%s    %s   => %s, %s", inst.op, inst.op1, inst.op2, inst.res);
      printf("\n%s    %s     => %s, %s", inst.op, inst.op1, inst.op2, inst.res);
      break;
    case ILOC_LE:
    case ILOC_LESS:
    case ILOC_EQ:
    case ILOC_GE:
    case ILOC_GREAT:
    case ILOC_DIF:
      fprintf(saida, "\n%s %s, %s     -> %s", inst.op, inst.op1, inst.op2, inst.res);
      printf("\n%s %s, %s    -> %s", inst.op, inst.op1, inst.op2, inst.res);
      break;
    case ILOC_LOADI:
      fprintf(saida, "\n%s %s        => %s", inst.op, inst.op1, inst.op2);
      printf("\n%s %s        => %s", inst.op, inst.op1, inst.op2);
      break;
    case ILOC_BR:
      fprintf(saida, "\n%s %s       -> %s, %s", inst.op, inst.op1, inst.op2, inst.res);
      printf("\n%s %s        -> %s, %s", inst.op, inst.op1, inst.op2, inst.res);
      break;
    case ILOC_JUMP:
      fprintf(saida, "\n%s            -> %s", inst.op, inst.op1);
      printf("\n%s           -> %s", inst.op, inst.op1);
      break;
    case ILOC_LABEL:
      fprintf(saida, "\n%s: %s %s, %s  => %s",inst.label, inst.op, inst.op1, inst.op2, inst.res);
      printf("\n%s:  %s %s, %s  => %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
      break;
    case ILOC_NOP:
      fprintf(saida, "\n%s", inst.op);
      printf("\n%s", inst.op);
      break;
    }
  }
  fclose(saida);
}

void print_list_ilocs(LISTA_ILOCS *l)
{
  LISTA_ILOCS *currentNode = l;
  while (currentNode != NULL)
  {
    print_iloc(currentNode->inst);
    printf("\n");
    currentNode = currentNode->next;
  }
  printf("\n");
}

void free_list(LISTA_ILOCS *l)
{
  LISTA_ILOCS *current, *next;

  current = l;

  while (current)
  {
    next = current->next;
    free(current);
    current = next;
  }
}

LISTA_ILOCS *concat_lista_ilocs(LISTA_ILOCS *l1, LISTA_ILOCS *l2)
{
  if (l1 == NULL)
    return l2;
  else if (l2 == NULL)
    return l1;

  LISTA_ILOCS *atual = l1;
  while (atual->next != NULL)
    atual = atual->next;

  atual->next = l2;
  return l1;
}

char *gera_temp(void)
{
  char *temp = (char *)malloc(MAX_LEN * sizeof(char));
  static int contador = 0;
  snprintf(temp, 200, "r%d", contador++);
  return temp;
}

char *gera_rotulo(void)
{
  char *label = (char *)malloc(MAX_LEN * sizeof(char));
  static int contador = 0;
  snprintf(label, 200, "L%d", contador++);
  return label;
}

/*
int main(){
  LISTA_ILOCS *l = NULL, *l2 = NULL;
  ILOC inst, inst2;

  inst = gera_inst(ILOC_ADD,"add","r1","r2",gera_temp());
  inst2 = gera_inst(ILOC_ADDI,"addi","r1","r2",gera_temp());
  inst2 = gera_inst_com_label("L0",inst2);

  insere_lista_ilocs(&l,inst);
  insere_lista_ilocs(&l,inst2);
  
  inst2 = gera_inst(ILOC_ADD,"add","r1","r100",gera_temp());
  insere_lista_ilocs(&l2,inst2);
  concat_lista_ilocs(l,l2);
  print_list_ilocs(l);

  return 0;
}
*/