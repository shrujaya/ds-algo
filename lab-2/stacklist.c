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
    printf("Here is a stack to play with!\n");
    printf("Choose what you want to do with it:\n");
    printf("1. Push an element into it\n");
    printf("2. Pop an element out of it\n");
    printf("3. Peek into the top element\n");
    printf("4. Display the stack\n");

    int choice;
    int n = 0;

    while(1) {
        printf ("Enter your choice 1/2/3/4 or -1 to quit!\n");
		scanf("%d", &choice);
		if (choice != -1) {
			switch(choice) {
			    case 1:
			        printf("Enter element to push: ");
			        scanf("%d", &n);
			        push(n);
			    break;
			    case 2:
			        printf("You popped: %d", pop());
			        printf("\n");
			    break;
			    case 3:
			        printf("The topmost element is: %d", peek());
			        printf("\n");
			    break;
			    case 4:
			        displaystack();
			    break;
			}
		}
		else {
			exit(1);
		}
    }
}

    /*
    push(3);
    push(4);
    displaystack();
    printf("The topmost element is: %d\n", peek(top));
    printf("You popped: %d\n", pop());
    displaystack(top);
    printf("The topmost element is: %d\n", peek(top));
    */

