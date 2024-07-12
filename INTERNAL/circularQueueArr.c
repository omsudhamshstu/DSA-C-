#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void insert();
void deleteItem();
void display();
int cq[SIZE], front = -1, rear = -1;

int main() {
    int ch;
    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:insert();break;
            case 2:deleteItem();break;
            case 3:display();break;
            case 4:exit(0);
            default:printf("Wrong choice\n");
        }
    }
    return 0;
}

void insert() {
    int item;
    if(front == (rear+1)%SIZE) {
        printf("Queue Overflow \n");
    } else {
        printf("Enter the element : ");
        scanf("%d", &item);
        rear = (rear+1) % SIZE;
        cq[rear] = item;
    }
    if(front == -1)
        front++;
}

void deleteItem() {
    int ele;
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        ele = cq[front];
        printf("Element deleted from queue is : %d\n", ele);
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front+1) % SIZE;
        }
    }
}

void display() {
    int i;
    if(front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\nQueue elements are: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%4d", cq[i]);
        }
        printf("%4d", cq[i]);
    }
}
