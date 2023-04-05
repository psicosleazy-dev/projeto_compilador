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
