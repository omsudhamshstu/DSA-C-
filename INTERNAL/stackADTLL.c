#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void count();

struct node {
    int data;
    struct node *link;
} *newnode, *top, *ptr;

int ch, item;

void main() {
    top = NULL;
    printf("**M E N U**");
    while (1) {
        printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Count\n 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                push(); 
                break;
            case 2: 
                pop(); 
                break;
            case 3: 
                display(); 
                break;
            case 4: 
                count(); 
                break;
            case 5: 
                exit(0);
            default: 
                printf("Invalid Choice!\n");
        }
    }
}

void push() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the item: ");
    scanf("%d", &item);
    newnode->data = item;
    newnode->link = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("\nSTACK IS EMPTY\n");
    } else {
        ptr = top;
        printf("Deleted element is: %d\n", ptr->data);
        top = top->link;
        free(ptr);
    }
}

void display() {
    if (top == NULL) {
        printf("The list is EMPTY\n");
    } else {
        printf("The elements in the stack are: ");
        for (ptr = top; ptr != NULL; ptr = ptr->link) {
            printf("%5d\n", ptr->data);
        }
    }
}

void count() {
    int count = 0;
    if (top == NULL) {
        printf("\nThe list is EMPTY\n");
    } else {
        for (ptr = top; ptr != NULL; ptr = ptr->link) {
            count++;
        }
        printf("\nThe number of elements in the stack are: %d\n", count);
    }
}
