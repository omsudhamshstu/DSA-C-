//20. (C program to check if a given binary tree is a complete binary tree)
#include <stdio.h>
#include <stdbool.h>

// Definition of a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to check if the binary tree is complete
bool isComplete(TreeNode *root) {
    if (root == NULL)
        return true;

    // Queue for level order traversal
    TreeNode *queue[100];
    int front = 0, rear = -1;
    bool flag = false;

    queue[++rear] = root;

    while (front <= rear) {
        TreeNode *temp = queue[front++];

        // If we have encountered a NULL node
        if (temp == NULL) {
            flag = true;
        } else {
            // If we have encountered a non-full node after a NULL node
            if (flag)
                return false;

            queue[++rear] = temp->left;
            queue[++rear] = temp->right;
        }
    }

    return true;
}

// Function to create a new tree node
TreeNode *newNode(int data) {
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    // Example binary tree creation
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->right->left = newNode(6);

    // Checking if the binary tree is complete
    if (isComplete(root))
        printf("The binary tree is a complete binary tree.\n");
    else
        printf("The binary tree is not a complete binary tree.\n");

    return 0;
}
