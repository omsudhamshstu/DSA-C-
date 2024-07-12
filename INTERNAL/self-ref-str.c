#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node node;
    node.data = 10;
    node.next = &node; // self-reference

    printf("Node data: %d\n", node.data);
    printf("Node next: %p\n", (void*)node.next);

    return 0;
}