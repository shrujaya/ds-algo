#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* right;
    struct _node* left;
} NODE;

NODE* createnode(int data) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void displaynode(NODE* node) {
    printf("%d ", node->data);
}

NODE* insert(NODE* root, int data) {
    if (root == NULL) {
        root = createnode(data);
    }
    else if (root->left == NULL) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        displaynode(root);
        inorder(root->right);
    }
}

int identical(NODE* t1, NODE* t2) {
    if (t1 == NULL && t2 == NULL) { //both trees are empty
        return 1;
    }

    if (t1 != NULL && t2 != NULL) { //trees aren't empty
        if (t1->data == t2->data && identical(t1->left, t2->left) &&
            identical(t1->right, t2->right)) {
            return 1;
        }
    }
    return 0; //one tree is filled, the other is empty
}

void main() {
    NODE* T1 = NULL;
    printf("BINARY TREE 1\n");
    while (1) {
        printf("Enter data of your node, type -1 to quit: ");
        int n = 0;
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        else {
            T1 = insert(T1, n);
        }
    }
    printf("Inorder representation of tree 1:\n");
    inorder(T1);
    printf("\n");

    NODE* T2 = NULL;
    printf("BINARY TREE 2\n");
    while (1) {
        printf("Enter data of your node, type -1 to quit: ");
        int n = 0;
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        else {
            T2 = insert(T2, n);
        }
    }
    printf("Inorder representation of tree 2:\n");
    inorder(T2);
    printf("\n");

    if (identical(T1, T2)) {
        printf("The two trees ARE identical!\n");
    }
    else {
        printf("The two trees ARE NOT identical!\n");
    }
}
