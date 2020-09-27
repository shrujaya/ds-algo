#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node* right;
    struct _node* left;
    bool lthread;
    bool rthread;
} NODE;

NODE* createnode(int data) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->lthread = true;
    newnode->rthread = true;
    return newnode;
}

void displaynode(NODE* node) {
    printf("%d ", node->data);
}

NODE* insert(NODE* root, int val) {
    NODE* ptr = root;
    NODE* parent = NULL;
    while (ptr != NULL) {
        parent = ptr;
        if (val < ptr->data) {
            if (ptr->lthread == false) {
                ptr = ptr->left;
            }
            else {
                break;
            }
        }
        else {
            if (ptr->rthread == false) {
                ptr = ptr->right;
            }
            else {
                break;
            }
        }
    }

    NODE* temp = createnode(val);

    if (parent == NULL) {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (val < parent->data) {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = false;
        parent->left = temp;
    }
    else {
        temp->left = parent;
        temp->right = parent->right;
        parent->rthread = false;
        parent->right = temp;
    }
    return root;
}

NODE* inordersuccessor(NODE* node) {
    if (node->rthread) {
        return node->right;
    }
    node = node->right;
    while (!(node->lthread)) {
        node = node->left;
    }
    return node;
}

void inorder(NODE* root) {
    if (root == NULL) {
        printf("Empty tree!\n");
    }

    NODE* node = root;
    while (!(node->lthread)) {
        node = node->left;
    }

    while (node != NULL) {
        displaynode(node);
        node = inordersuccessor(node);
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
}
