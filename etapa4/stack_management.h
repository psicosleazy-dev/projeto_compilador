#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

typedef struct stack_node{
    HASH_TABLE *data;
    struct stack_node *next;
}stack_node;

typedef struct Stack{
    stack_node *head;
    int size;
}Stack;

Stack* create_stack();
void push(Stack* stack, HASH_TABLE* data);
HASH_TABLE* pop(Stack* stack);
stack_node* retrieve(Stack* stack, int level); //get something below
int empty_stack(Stack* stack);
void print_stack(Stack* stack);
void delete_stack(Stack* stack); //free everything
#endif
