#include <stdio.h>
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
    push1(3);
    printstack1();
    push1(4);
    printstack1();
    push1(5);
    printstack1();
    push2(5);
    printstack2();

    pop1();
    printstack1();
    pop1();
    printstack1();
    push2(10);
    pop2();
    printstack2();
    pop2();
    printstack2();
}
