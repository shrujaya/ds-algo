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

float cuboid_volume(float l, float b, float h) {
    return l * b * h;
}

float cone_volume(float r, float h) {
    return 0.333 * PI * r * r * h;
}

float sphere_volume(float r) {
    return 1.333 * PI * r * r * r;
}

void main() {
    printf("What shape would you like to find the area/volume of?\n");
    printf("----------AREAS----------\n");
    printf("1. Square (given its side length)\n");
    printf("2. Triangle (given its base length and height)\n");
    printf("3. Circle (given its radius)\n");
    printf("----------VOLUMES----------\n");
    printf("4. Cuboid (given its length, breadth and height)\n");
    printf("5. Cone (given its base radius and height)\n");
    printf("6. Sphere (given its radius)\n");
    printf("Enter your choice - 1/2/3/4/5/6!\n");
    int choice;
    scanf("%d", &choice);

    float l, s, b, h, r;

    switch (choice) {
        case 1:
            printf("Enter side length: ");
            scanf("%f", &s);
            printf("Area is: %.2f\n", square_area(s));
        break;
        case 2:
            printf("Enter base length: ");
            scanf("%f", &b);
            printf("Enter height: ");
            scanf("%f", &h);
            printf("Area is: %.2f\n", triangle_area(b, h));
        break;
        case 3:
            printf("Enter radius: ");
            scanf("%f", &r);
            printf("Area is : %.2f\n", circle_area(r));
        break;
        case 4:
            printf("Enter length: ");
            scanf("%f", &l);
            printf("Enter breadth: ");
            scanf("%f", &b);
            printf("Enter height: ");
            scanf("%f", &h);
            printf("Volume is: %.2f\n", cuboid_volume(l, b, h));
        break;
        case 5:
            printf("Enter base radius: ");
            scanf("%f", &r);
            printf("Enter height: ");
            scanf("%f", &h);
            printf("Volume is: %.2f\n", cone_volume(r, h));
        break;
        case 6:
            printf("Enter radius: ");
            scanf("%f", &r);
            printf("Volume is: %.2f\n", sphere_volume(r));
        break;
    }
}
