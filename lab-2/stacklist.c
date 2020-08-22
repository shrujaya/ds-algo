#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* next;
} NODE;

static NODE* top = NULL;

void push(int data) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

int isEmpty() {
    return (top == NULL) ? 1 : 0;
}

int pop() {
    if (isEmpty(top)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    int popped = top->data;
    top = top->next;
    return popped;
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return top->data;
}

void displaystack() {
    NODE* ptr = top;
    while (ptr) {
        printf("%d ", ptr->data);
        printf("--> ");
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void main() {
    push(3);
    push(4);
    displaystack();
    printf("The topmost element is: %d\n", peek(top));
    printf("You popped: %d\n", pop());
    displaystack(top);
    printf("The topmost element is: %d\n", peek(top));
}
