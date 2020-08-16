#include <stdio.h>
#define PI 3.14159265

float square_area(float s) {
    return s*s;
}

float triangle_area(float b, float h) {
    return 0.5 * b * h;
}

float circle_area(float r) {
    return PI * r * r;
}

void main() {
    printf("What shape would you like to find the area of?\n");
    printf("1. Square (given its side length)\n");
    printf("2. Triangle (given its base length and height)\n");
    printf("3. Circle (given its radius)\n");
    printf("Enter your choice - 1/2/3!\n");
    int choice;
    scanf("%d", &choice);

    float s, b, h, r;

    switch (choice) {
        case 1:
            printf("Enter side length: ");
            scanf("%f", &s);
            printf("Area is: %f\n", square_area(s));
        break;
        case 2:
            printf("Enter base length: ");
            scanf("%f", &b);
            printf("Enter height: ");
            scanf("%f", &h);
            printf("Area is: %f\n", triangle_area(b, h));
        break;
        case 3:
            printf("Enter radius: ");
            scanf("%f", &r);
            printf("Area is : %f\n", circle_area(r));
        break;
    }
}
