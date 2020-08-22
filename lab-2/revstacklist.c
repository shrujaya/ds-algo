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

int length() {
    NODE* ptr = top;
    int count = 0;
    while(ptr) {
        count++;
        ptr=ptr->next;
    }
    return count;
}

int isEmpty() {
    return (top == NULL) ? 1 : 0;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(-1);
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

//pop 'n' elements out of our stack and return them in a linked list
NODE* drain(int n) {
    if (n > length()) {
        return NULL;
    }

    NODE* last = NULL;
    for (int i = 0; i < n; i++) {
        int item = pop();
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        temp->data = item;
        temp->next = last;
        last = temp;
    }
    return last;
}

//put the elements in the linked list back into the stack
void undrain(NODE* list) {
    while (list) {
        push(list->data);
        NODE* temp = list;
        list= list->next;
        free(temp);
    }
}

void reverse(int n) {
    if (n < 1) return;

    int item = pop();
    NODE* temp = drain(n - 1);
    push(item);
    undrain(temp);

    reverse(n - 1);
}

void makeStack(int array[], int n) {
    for (int i = 0; i < n; i++) {
        push(array[i]);
    }
}

void main() {
    int items[] = {1, 2, 3, 4, 5, 6};

    makeStack(items, 6);
    displaystack();
    reverse(length());
    displaystack();
}
