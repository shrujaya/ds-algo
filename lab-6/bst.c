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
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

NODE* min(NODE* node) {
    //finding the leftmost leaf
    NODE* curr = node;
    while ((curr) && (curr->left != NULL)) {
        curr = curr->left;
    }
    return curr;
}

NODE* delete(NODE* root, int data) {
    NODE* temp = NULL;
    if (root == NULL) {
        printf("No such element exists!");
    }
    else if (data < root->data) {
        root->left = delete(root->left, data);
    }
    else if  (data > root->data) {
        root->right = delete(root->right, data);
    }
    else {
        if (root->right && root->left) {
            temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        else {
            if (root->left == NULL) {
                temp = root->right;
            }
            else {
                temp = root->left;
            }
            free(root);
            root = temp;
        }
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

void main() {
    NODE* root = NULL;
    while (1) {
        printf("Enter data of your node, type -1 to quit: ");
        int n = 0;
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        else {
            root = insert(root, n);
        }
    }
    printf("Inorder representation of tree:\n");
    inorder(root);
    printf("\n");
    while (1) {
        printf("Enter data to delete, type -1 to quit: ");
        int n = 0;
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        else {
            root = delete(root, n);
            printf("Inorder representation of tree:\n");
            inorder(root);
            printf("\n");
        }
    }
}
