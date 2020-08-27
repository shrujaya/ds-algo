#include <stdio.h>
#include <stdlib.h>
#define LEN 3

int stack[LEN];
int top1 = -1;
int top2 = LEN;

void push1(int data) {
    if (top1 < top2 - 1) {
        stack[++top1] = data;
    }
    else {
        printf("Stack1 Overflow!\n");
    }
}

void push2(int data) {
    if (top1 < top2 - 1) {
        stack[--top2] = data;
    }
    else {
        printf("Stack2 Overflow!\n");
    }
}

void pop1() {
    if (top1 >= 0) {
        int popped = stack[top1--];
        printf("You popped \'%d\' from Stack1\n", popped);
    }
    else {
        printf("Stack1 Underflow!\n");
    }
}

void pop2() {
    if (top2 < LEN) {
        int popped = stack[top2++];
        printf("You popped \'%d\' from Stack2\n", popped);
    }
    else {
        printf("Stack2 Underflow!\n");
    }
}

void printstack1() {
    printf("Stack 1 : ");
    for (int i = top1; i >= 0; i--) {
        printf("%d --> ", stack[i]);
    }
    printf("NULL\n");
}

void printstack2() {
    printf("Stack 2 : ");
    for (int i = top2; i < LEN; i++) {
        printf("%d --> ", stack[i]);
    }
    printf("NULL\n");
}

void main() {
    printf("Here are 2 stacks to play with!\n");
    printf("Choose what you want to do with them:\n");
    printf("1. Push an element into stack1\n");
    printf("2. Push an element into stack2\n");
    printf("3. Pop an element out of stack1\n");
    printf("4. Pop an element out of stack2\n");
    printf("5. Display stack1\n");
    printf("6. Display stack2\n");

    int choice;
    int n = 0;

    while(1) {
        printf ("Enter your choice 1/2/3/4/5/6 or -1 to quit!\n");
        scanf("%d", &choice);
        if (choice != -1) {
            switch(choice) {
                case 1:
                    printf("Enter element to push: ");
                    scanf("%d", &n);
                    push1(n);
                break;
                case 2:
                    printf("Enter element to push: ");
                    scanf("%d", &n);
                    push2(n);
                break;
                case 3:
                    pop1();
                break;
                case 4:
                    pop2();
                break;
                case 5:
                    printstack1();
                break;
                case 6:
                    printstack2();
                break;
            }
        }
        else {
            exit(1);
        }
    }
}
