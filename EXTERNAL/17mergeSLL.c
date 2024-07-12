#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge_lists(struct Node* list1, struct Node* list2) {
    struct Node dummy; // dummy node to ease handling of the result list
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (1) {
        if (list1 == NULL) {
            tail->next = list2;
            break;
        }
        else if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    return dummy.next;
}

// Example usage
int main() {
    // Example lists
    struct Node* list1 = malloc(sizeof(struct Node));
    list1->data = 1;
    list1->next = malloc(sizeof(struct Node));
    list1->next->data = 3;
    list1->next->next = NULL;

    struct Node* list2 = malloc(sizeof(struct Node));
    list2->data = 2;
    list2->next = malloc(sizeof(struct Node));
    list2->next->data = 4;
    list2->next->next = NULL;

    // Merge lists
    struct Node* merged = merge_lists(list1, list2);

    // Print merged list
    struct Node* temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}