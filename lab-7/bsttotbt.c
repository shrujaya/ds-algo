#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node* right;
    struct _node* left;
    bool isthreaded;
} NODE;

NODE* thread(NODE* root) {
    //if tree is empty
    if (root == NULL) {
        return NULL;
    }

    //if tree only consists of root
    if (!(root->left) && !(root->right)) {
        return root;
    }

    //if inorder predecessor exists, link predecessor to current node
    if (root->left) {
        NODE* l = thread(root->left);
        l->right = root;
        l->isthreaded = true;
    }

    //if current node is rightmost child
    if (!root->right) {
        return root;
    }

    return thread(root->right);
}

NODE* createnode(int data) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->isthreaded = false;
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

void inorder(NODE* root) {
    if (root == NULL) return;

    NODE* curr = min(root);

    while (curr != NULL) {
        displaynode(curr);
        if (curr->isthreaded) {
            curr = curr->right;
        }
        else {
            curr = min(curr->right);
        }
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

    thread(root);
    printf("Inorder representation of tree:\n");
    inorder(root);
    printf("\n");
}
