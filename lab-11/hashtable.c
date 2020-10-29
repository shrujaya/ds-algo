#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 8

struct entry {
    char* data;
    int key;
};

struct entry* hashArray[SIZE];
struct entry* dummy;
struct entry* item;

int hashCode(int key) {
    //simple hash code calculation
    return key % SIZE;
}

void insert(int key, char* data) {

    struct entry *item = (struct entry*) malloc(sizeof(struct entry));
    item->data = malloc(strlen(data) + 1);
    strcpy(item->data, data);
    item->key = key;

    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

void display() {
    for(int i = 0; i<SIZE; i++) {
        if(hashArray[i] != NULL)
            printf("(%d, %s) ",hashArray[i]->key,hashArray[i]->data);
        else
            printf("EMPTY ");
    }
    printf("\n");
}

int main() {
    dummy = (struct entry*) malloc(sizeof(struct entry));
    dummy->data = NULL;
    dummy->key = -1;

    for (int i = 0; i < SIZE; i++) {
        int k;
        char* str;
        printf("Enter key (-1 to quit): ");
        scanf("%d", &k);
        if (k == -1) {
            break;
        }
        printf("Enter data string: ");
        scanf("%s", str);

        insert(k, str);
    }
    display();
}

