/*16. (to split a given list of integers represented by a singly linked list into two lists in the following way:
Let the list be L = (l0, l1, l2, l3,………, ln)
The resultant lists would be R1 = (l0, l2, l4, ……. ) & R2 = (l1, l3, l5, ……….).)*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void splitList(struct Node *head, struct Node **head1, struct Node **head2) {
    struct Node *curr = head;
    *head1 = head;
    *head2 = head->next;
    while (curr != NULL && curr->next != NULL) {
        curr->next = curr->next->next;
        curr = curr->next;
    }
}

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original Linked list: ");
    printList(head);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    splitList(head, &head1, &head2);

    printf("\nSplitted Linked list 1: ");
    printList(head1);

    printf("\nSplitted Linked list 2: ");
    printList(head2);

    return 0;
}