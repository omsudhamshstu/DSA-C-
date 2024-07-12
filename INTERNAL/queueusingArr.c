#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void enqueue(int item);
void dequeue();
void display();
int isEmpty();

int queue[MAX_SIZE];
int front = -1, rear = -1;

int main() {
    int ch, item;

    printf("\n\n MENU");
    printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the item: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice!");
        }
    }
    return 0;
}

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (isEmpty()) {
        printf("\nThe list is EMPTY!");
        return;
    }
    printf("\nThe deleted element is: %d", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nThe list is EMPTY!");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int isEmpty() {
    return (front == -1 || front > rear);
}