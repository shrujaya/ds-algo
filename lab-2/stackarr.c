#include <stdio.h>
#include <stdlib.h>
#define LEN 10

static int stack[LEN];
int top = -1;

void push(int n) {
    if (top == LEN - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    else {
        top++;
        stack[top] = n;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    else {
        int item = stack[top];
        top--;
        return item;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    else {
        return stack[top];
    }
}

void displayelement(int n) {
    printf("%d ", n);
}

void displaystack() {
    for (int i = top; i >= 0; i--) {
        displayelement(stack[i]);
        printf("--> ");
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
                    printf("You popped: ");
                    displayelement(pop());
                    printf("\n");
                break;
                case 3:
                    printf("The topmost element is: ");
                    displayelement(peek());
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
