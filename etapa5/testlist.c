#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

void printList(Node *head) {
    Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    // insere alguns elementos na lista
    for (int i = 1; i <= 5; i++) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->value = i;
        newNode->next = head;
        head = newNode;
    }

    // imprime a lista
    printList(head);

    return 0;
}