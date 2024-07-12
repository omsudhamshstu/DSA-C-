#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node *head) {
    struct Node *current = head;
    struct Node *next_next;

    if (current == NULL) return;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(20);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(30);
    head->next->next->next->next->next = newNode(30);

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
