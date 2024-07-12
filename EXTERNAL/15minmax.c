//15 (to find the minimum and maximum elements in a Binary Search Tree.)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void findMinMax(struct Node* root, int* min, int* max) {
  if (root == NULL) {
    return;
  }
  if (*min > root->data) {
    *min = root->data;
  }
  if (*max < root->data) {
    *max = root->data;
  }
  findMinMax(root->left, min, max);
  findMinMax(root->right, min, max);
}

int main() {
  struct Node* root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);

  int min = INT_MAX;
  int max = INT_MIN;

  findMinMax(root, &min, &max);

  printf("Minimum element is %d\n", min);
  printf("Maximum element is %d\n", max);

  return 0;
}