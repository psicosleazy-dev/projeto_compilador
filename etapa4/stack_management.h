#include<stdio.h>
#include<stdlib.h>

typedef struct Table{
    int placeholder;
}Table;

typedef struct stack_node{
    Table *data;
    struct stack_node *next;
}stack_node;

typedef struct Stack{
    stack_node *head;
    int size;
}Stack;

Stack* create_stack();
void push(Stack* stack, Table* data);
void pop(Stack* stack);
stack_node* retrieve(Stack* stack, int level); //get something below
void delete_stack(Stack* stack); //free everything
