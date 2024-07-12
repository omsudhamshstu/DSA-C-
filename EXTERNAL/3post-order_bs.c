#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void postOrder(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;

    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];

        if (current->right && current->right != stack[top+1]) {
            stack[++top] = current;
            current = current->right;
        } else {
            printf("%d ", current->data);
            current = NULL;
        }
    }
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    postOrder(root);

    return 0;
}