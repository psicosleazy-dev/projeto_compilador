#include "stack_management.h"

Stack* create_stack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, Table *data){
    stack_node* new_element = malloc(sizeof(struct stack_node));
    new_element->data = data;
    new_element->next = stack->head;
    stack->head = new_element;
    stack->size+=1;
}

void pop(Stack* stack){
    stack_node* temp = stack->head->next;
    free(stack->head); //maybe unnecessary
    free(stack);
    stack->head = temp;
    stack->size-=1;
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
    while (stack->head->next != NULL){
        pop(stack);
    }
    free(stack);
} //free all
