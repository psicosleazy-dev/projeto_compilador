#include "stack_management.h"

int empty_stack(Stack* stack){
     if(stack->head == NULL)
        return 1;
     else
        return 0;
}

Stack* create_stack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, HASH_TABLE* table){
    stack_node* new_element = malloc(sizeof(struct stack_node));
    new_element->data = table;
    new_element->next = stack->head;
    stack->head = new_element;
    stack->size+=1;
}

HASH_TABLE* pop(Stack* stack){
    if(empty_stack(stack)){
        printf("pilha vazia!\n");
        exit(4);
    }
    else{
        stack_node* temp = stack->head->next;
        HASH_TABLE* table = stack->head->data;
        stack->head = temp;
        stack->size-=1;
        return table;
    }
}

stack_node* retrieve(Stack* stack, int level){
    if (stack->size < level)
        printf("Stack isn't that long yet\n");
    stack_node* temp = stack->head;
    level -= 1;
    while(level > 0){
        temp = temp->next;
        level--;
    }
    return temp;
} //get something below

void delete_stack(Stack* stack){
    stack_node *atual, *prox;
    atual = stack->head->next;
    while(atual != NULL){
        prox = atual->next;
        free(atual);
        atual = prox;
    }
} //free all

void print_stack(Stack* stack){
    stack_node *atual;
    atual = stack->head;
    while(atual!=NULL){
        print_table(atual->data);
        atual = atual->next;
    }
}

HASH_ENT* search_stack(Stack* stack, char* simbolo){
    stack_node* aux;
    aux = stack->head;
    HASH_ENT* achou;
    while(aux){
        achou = ht_search(aux->data,simbolo);
        if(achou)
            return achou;
        aux = aux->next;
    }

    return NULL;
}

int retorna_end_desloc(Stack *stack, valor_t simbolo)
{
  HASH_ENT *ent = NULL;
  ent = search_stack(stack, simbolo.value.token);

  if (ent)
    return ent->desloc;
  else{
    printError(ERR_UNDECLARED, simbolo.value.token,0);
    return 0;
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

char* retorna_label(Stack* s, char* token)
{
    HASH_ENT *ent = NULL;
    ent = search_stack(s,token);
    if (ent)
        return ent->valor_lexico.label;
    return "NULL";
}

void checkTableDec(Stack* stack, valor_t novo_simbolo)
{
    HASH_ENT* tmp = search_stack(stack,novo_simbolo.value.token);
    if(tmp)
    {
        if(tmp->valor_lexico.tipo != novo_simbolo.tipo)
            printError(ERR_DECLARED, novo_simbolo.value.token, tmp->valor_lexico.tipo);
        if((tmp->valor_lexico.natureza == NAT_VARIABLE) && ((novo_simbolo.natureza == NAT_ARRAY)))
            printError(ERR_VARIABLE, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.natureza == NAT_ARRAY) && ((novo_simbolo.natureza == NAT_VARIABLE) || (novo_simbolo.natureza == NAT_FUNCTION)))
            printError(ERR_ARRAY, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.natureza == NAT_FUNCTION) && ((novo_simbolo.natureza == NAT_VARIABLE) || (novo_simbolo.natureza == NAT_ARRAY)))
            printError(ERR_FUNCTION, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.tipo == INT_TYPE))
            printError(ERR_CHAR_TO_INT, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.tipo == FLOAT_TYPE))
            printError(ERR_CHAR_TO_FLOAT, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.tipo == BOOL_TYPE))
            printError(ERR_CHAR_TO_BOOL, novo_simbolo.value.token,0);
        if(((tmp->valor_lexico.tipo == INT_TYPE) || (tmp->valor_lexico.tipo == FLOAT_TYPE) || (tmp->valor_lexico.tipo == BOOL_TYPE)) && (novo_simbolo.tipo == CHAR_TYPE))
            printError(ERR_X_TO_CHAR, novo_simbolo.value.token,0);
        if((tmp->valor_lexico.tipo == CHAR_TYPE) && (novo_simbolo.natureza == NAT_ARRAY))
            printError(ERR_CHAR_VECTOR, novo_simbolo.value.token,0);
    }
}

void checkTableInUse(Stack* stack, valor_t novo_simbolo){
    HASH_ENT* tmp = search_stack(stack,novo_simbolo.value.token);
    if(!tmp)
        printError(ERR_UNDECLARED,novo_simbolo.value.token,0);
    else
        checkTableDec(stack,novo_simbolo);
}

int retorna_tipo_simbolo(valor_t s, Stack* stack){
    HASH_ENT* achou = search_stack(stack,s.value.token);
    if(achou)
        return achou->valor_lexico.tipo;
    else
        printError(ERR_UNDECLARED,s.value.token,s.tipo);
    return 0;
}
// alterar para que inuse faça a verificacao na pilha e dec apenas na tabela!!!!

void insere_lista_na_tabela(LISTA* l, Stack* stack){
    LISTA* aux = NULL;
    HASH_TABLE *table = NULL;

    for(aux = l; aux!=NULL; aux=aux->prox){
        checkTableDec(stack,aux->valor_lexico);
        table = pop(stack);
        aux->valor_lexico = altera_tamanho(aux->valor_lexico);
        insert_item(table,aux->valor_lexico);
        push(stack,table);
    }
}

/*
int main(){
    Stack *stack = create_stack();
    HASH_TABLE* table;
    table = create_table(HASH_SIZE);
    valor_t value;
    value.linha = 1;
    value.natureza = NAT_VARIABLE;
    value.tamanho = 1;
    value.tipo = INT_TYPE;
    value.value.token = "valor";

    insert_item(table,value);

    push(stack,table);

    print_stack(stack);

    HASH_TABLE* table2 = pop(stack);

    printf("\npilha depois do pop\n");

    print_stack(stack);

    delete_stack(stack);

    return 0;
}*/
