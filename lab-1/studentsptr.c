#include <stdio.h>
#include <stdlib.h>
#define LEN 100

typedef struct _student {
    char* name;
    int reg;
    float gpa;
} STUDENT;

STUDENT* read(STUDENT* s, char* name, int reg, float gpa) {
    s->name = name;
    s->reg = reg;
    s->gpa = gpa;
    return s;
}

void display(STUDENT* s) {
    printf("Name: %s\n", s->name);
    printf("Register Number: %d\n", s->reg);
    printf("GPA: %.2f\n", s->gpa);
}

void main() {
    int n, reg = 0;
    float gpa;

    printf("Enter the number of students: ");
    scanf ("%d", &n);
    STUDENT* students = (STUDENT*)malloc(sizeof(STUDENT) * n);

    for (int i = 0; i < n; i++) {
        char* name = (char*)malloc(sizeof(char) * LEN);
        printf("Enter student's name: ");
        scanf("%s", name);
        printf("Enter student's register number: ");
        scanf("%d", &reg);
        printf("Enter student's GPA: ");
        scanf("%f", &gpa);
        read(students + i, name, reg, gpa);
    }

    printf("\nLIST OF STUDENTS:\n");
    for (int i = 0; i < n; i++) {
        display(students + i);
        free(students[i].name);
        printf("\n");
    }
    free(students);
}
