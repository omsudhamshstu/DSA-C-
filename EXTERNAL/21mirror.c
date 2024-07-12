//21. (WACP to convert Binary tree to its mirror.)
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

void mirror(struct Node* node) {
  if (node == NULL) {
    return;
  }
  struct Node* temp;
  mirror(node->left);
  mirror(node->right);
  temp = node->left;
  node->left = node->right;
  node->right = temp;
}

void inorder(struct Node* node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("Inorder traversal of the original tree: ");
  inorder(root);
  printf("\n");

  mirror(root);

  printf("Inorder traversal of the mirror tree: ");
  inorder(root);
  printf("\n");

  return 0;
}