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
        exit(1);
    }
    return head;
}

PLAYER* makeplayer() {
    PLAYER* newplayer = (PLAYER*)malloc(sizeof(PLAYER));
    printf ("Enter the name of your player, (type \"quit\" to quit): ");
    char name[100];
    scanf("%s", name);

    if (strcmp(name, "quit") == 0) {
        return NULL;
    }
    else {
        newplayer->name = malloc(strlen(name) + 1);
        strcpy(newplayer->name, name);

        printf("Enter their jersey number: ");
        scanf("%d", &newplayer->num);

        newplayer->next = NULL;
        return newplayer;
    }
}

void main() {
    PLAYER *head = makeplayer();
    PLAYER *next;
    while (next = makeplayer())  {
        int position;
        printf("Enter the position to insert at (enter -1 to append): ");
        scanf("%d", &position);
        if (position < 0) {
            head = append(head, next);
        } else {
            head = insertat(head, position, next);
        }
    }

    printlist(head);
    int num;
    printf("Enter a number to search for a player by: ");
    scanf("%d", &num);
    printnode(getplayerbynumber(head, num));
    printf("\n");
}

