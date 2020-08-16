#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _player {
    char* name;
    int num;
    struct _player* next;
} PLAYER;


void printnode(PLAYER* player) {
        printf("[%s, %d] ", player->name, player->num);
}
void printlist(PLAYER* ptr) {
    while (ptr) {
        printnode(ptr);
        printf("--> ");
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int len(PLAYER* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

PLAYER* insertat(PLAYER* head, int pos, PLAYER* player) {
    int length = len(head);
    if (pos > length) {
       printf("Error, invalid position!\n");
       return NULL;
    }

    int currindex = 0;
    PLAYER* curr = head;
    PLAYER* prev = NULL;
    while (currindex < pos) {
        prev = curr;
        curr = curr->next;
        currindex++;
    }

    if (prev != NULL) {
        prev->next = player;
    }
    else {
        head = player;
    }
    player->next = curr;
    return head;
}

PLAYER* append(PLAYER* head, PLAYER* player) {
    int length = len(head);
    return insertat(head, length, player);
}

PLAYER* del(PLAYER* head, int num) {
    PLAYER* prev = NULL;
    PLAYER* curr = head;
    while (curr) {
        if (curr->num == num) {
            prev->next = curr->next;
            curr->next = NULL;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

PLAYER* getplayerbynumber(PLAYER* head, int num) {
    while (head) {
        if (head->num == num) { return head; }
        head = head->next;
    }
    if (head == NULL) {
        printf("Not found!\n");
    }
    return head;
}

PLAYER* makeplayer(char* name, int num) {
    PLAYER* newplayer = (PLAYER*)malloc(sizeof(PLAYER));
    newplayer->name = name;
    newplayer->num = num;
    newplayer->next = NULL;
    return newplayer;
}

void main() {
    PLAYER* head = makeplayer("shru", 1);
    PLAYER* dad = makeplayer("shiv", 2);
    head = insertat(head, 0, dad);
    PLAYER* mom = makeplayer("pri", 3);
    head = append(head, mom);
    printnode(getplayerbynumber(head, 2));
    printf("\n");
    printlist(head);
    head = del(head, 1);
    printlist(head);
}
