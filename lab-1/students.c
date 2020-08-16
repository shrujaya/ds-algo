#include <stdio.h>
#include <stdlib.h>
#define LEN 100

typedef struct _student {
    char* name;
    int reg;
    float gpa;
} STUDENT;

STUDENT read(STUDENT s, char* name, int reg, float gpa) {
    s.name = name;
    s.reg = reg;
    s.gpa = gpa;
    return s;
}

void display(STUDENT s) {
    printf("Name: %s\n", s.name);
    printf("Register Number: %d\n", s.reg);
    printf("GPA: %.2f\n", s.gpa);
}

void main() {
    int reg = 0;
    float gpa;

    STUDENT student;
    char* name = (char*)malloc(sizeof(char) * LEN);
    printf("Enter student's name: ");
    scanf("%s", name);
    printf("Enter student's register number: ");
    scanf("%d", &reg);
    printf("Enter student's GPA: ");
    scanf("%f", &gpa);

    student = read(student, name, reg, gpa);

    printf("\nDETAILS:\n");
    display(student);

    free(student.name);
}
