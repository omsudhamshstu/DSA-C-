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

int findHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return 1 + (leftHeight > rightHeight? leftHeight : rightHeight);
}

int main() {
    Node* root = createNode(11);
    root->left = createNode(4);
    root->right = createNode(19);
    root->left->left = createNode(1);
    root->left->right = createNode(9);
    root->right->left = createNode(12);
    root->right->right = createNode(23);
    int height = findHeight(root);
    printf("The height of the binary tree is: %d\n", height);
    return 0;
}
