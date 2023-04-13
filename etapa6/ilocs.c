#include <stdio.h>
#include "ilocs.h"

void insere_lista_ilocs(LISTA_ILOCS **lista, ILOC inst)
{
  LISTA_ILOCS *p = (LISTA_ILOCS *)malloc(sizeof(LISTA_ILOCS));
  p->inst = inst;
  p->next = NULL;

  if (*lista == NULL)
  {
    *lista = p;
    printf("inseriu");
  }
  else
  {
    LISTA_ILOCS *aux = *lista;
    while (aux->next)
      aux = aux->next;
    aux->next = p;
    printf("inseriu");
  }
}

ILOC gera_inst(int tipo, char *op, char *op1, char *op2, char *res)
{
  ILOC inst;

  inst.tipo_iloc = tipo;
  inst.eh_label = 0;
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
  inst.eh_label = 1;
  return inst;
}

void print_iloc(ILOC inst,FILE* saida)
{
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
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s    %s, %s  => %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s:  %s      %s, %s  => %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
      }
      else
      {
        fprintf(saida, "\n%s    %s, %s => %s", inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s    %s, %s => %s", inst.op, inst.op1, inst.op2, inst.res);
      }
      break;
    case ILOC_ATT:
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s    %s   => %s, %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s: %s    %s     => %s, %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
      }
      else
      {
        fprintf(saida, "\n%s    %s   => %s, %s", inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s    %s     => %s, %s", inst.op, inst.op1, inst.op2, inst.res);
      }
      break;
    case ILOC_LE:
    case ILOC_LESS:
    case ILOC_EQ:
    case ILOC_GE:
    case ILOC_GREAT:
    case ILOC_DIF:
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s %s, %s     -> %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s: %s %s, %s    -> %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
      }
      else
      {
        fprintf(saida, "\n%s %s, %s     -> %s", inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s %s, %s    -> %s", inst.op, inst.op1, inst.op2, inst.res);
      }
      break;
    case ILOC_LOADI:
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s %s        => %s", inst.label, inst.op, inst.op1, inst.res);
        printf("\n%s: %s %s        => %s", inst.label, inst.op, inst.op1, inst.res);
      }
      else
      {
        fprintf(saida, "\n%s %s        => %s", inst.op, inst.op1, inst.res);
        printf("\n%s %s        => %s", inst.op, inst.op1, inst.res);
      }
      break;
    case ILOC_BR:
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s %s       -> %s, %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s: %s %s        -> %s, %s", inst.label, inst.op, inst.op1, inst.op2, inst.res);
      }
      else
      {
        fprintf(saida, "\n%s %s       -> %s, %s", inst.op, inst.op1, inst.op2, inst.res);
        printf("\n%s %s        -> %s, %s", inst.op, inst.op1, inst.op2, inst.res);
      }
      break;
    case ILOC_JUMP:
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s            -> %s", inst.label, inst.op, inst.res);
        printf("\n%s: %s           -> %s", inst.label, inst.op, inst.res);
      }
      else
      {
        fprintf(saida, "\n%s            -> %s", inst.op, inst.res);
        printf("\n%s           -> %s", inst.op, inst.res);
      }
      break;
    case ILOC_NOP:
      if (inst.eh_label)
      {
        fprintf(saida, "\n%s: %s", inst.label, inst.op);
        printf("\n%s: %s", inst.label, inst.op);
      }
      else
      {
        fprintf(saida, "\n%s", inst.op);
        printf("\n%s", inst.op);
      }
      break;
    }
  }
  
}

int tam_lista_ilocs(LISTA_ILOCS *l)
{
  int cont = 0;
  LISTA_ILOCS *aux = l;
  while (aux->next)
  {
    aux = aux->next;
    cont++;
  }
  return cont;
}

void print_list_ilocs(LISTA_ILOCS *l)
{
  // montando as instrucoes de cabeçalho
  LISTA_ILOCS *intro = NULL, *currentNode = NULL;
  ILOC inst;
  int body;
  inst = gera_inst(ILOC_LOADI, "loadI", "0", "null", "rfp");
  insere_lista_ilocs(&intro, inst);
  inst = gera_inst(ILOC_LOADI, "loadI", "0", "null", "rsp");
  insere_lista_ilocs(&intro, inst);
  body = tam_lista_ilocs(l);
  body = body + 4;
  char buf[2];
  sprintf(buf, "%d", body);
  inst = gera_inst(ILOC_LOADI, "loadI", buf, "null", "rbss");
  insere_lista_ilocs(&intro, inst);
  intro = concat_lista_ilocs(intro, l);
  currentNode = intro;

  FILE *saida = fopen("saida", "w+");

  while (currentNode != NULL)
  {
    print_iloc(currentNode->inst,saida);
    currentNode = currentNode->next;
  }
  printf("\n");

  fclose(saida);
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

void generateAsm(LISTA_ILOCS* l, Stack* s){
  
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