#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();

int ch, item;

struct node {
    int data;
    struct node *link;
} *front, *rear, *neww, *ptr;

int main() {
    front = rear = NULL;
    printf("\n\n MENU");
    printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nWrong choice!");
        }
    }
}

void enqueue() {
    neww = (struct node *)malloc(sizeof(struct node));
    if (neww == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    printf("\nEnter the item: ");
    scanf("%d", &item);
    neww->data = item;
    neww->link = NULL;

    if (front == NULL) {
        front = neww;
    } else {
        rear->link = neww;
    }
    rear = neww;
}

void dequeue() {
    if (front == NULL) {
        printf("\nThe list is EMPTY!");
        return;
    } else {
        ptr = front;
        printf("\nThe deleted element is: %d", ptr->data);
        if (front == rear) { // List has a single element
            front = rear = NULL;
        } else {
            front = front->link;
        }
        free(ptr);
    }
}

void display() {
    if (front == NULL) {
        printf("\nThe list is EMPTY!");
    } else {
        printf("\nQueue elements: ");
        for (ptr = front; ptr != NULL; ptr = ptr->link) {
            printf(" %d", ptr->data);
        }
    }
}
