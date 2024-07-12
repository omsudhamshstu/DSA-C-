#include <stdio.h>

// Mid-Square method
int midSquareHash(int key, int tableSize) {
  key = key * key;
  return (key / 100) % tableSize;
}

// Simple Hashing
int simpleHash(int key, int tableSize) { return key % tableSize; }

int main() {
  int key, tableSize;

  printf("Enter the key: ");
  scanf("%d", &key);

  printf("Enter the table size: ");
  scanf("%d", &tableSize);

  printf("Mid-Square Hash: %d\n", midSquareHash(key, tableSize));
  printf("Simple Hash: %d\n", simpleHash(key, tableSize));

  return 0;
}
