#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void copyStack(struct Stack* source, struct Stack* destination) {
    if (source->top == NULL) {
        return;
    }
    while (source->top != NULL) {
        int data = pop(source);
        push(destination, data);
    }
}

void displayStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();

    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);

    printf("Stack 1: ");
    displayStack(stack1);

    copyStack(stack1, stack2);

    printf("Stack 2: ");
    displayStack(stack2);

    return 0;
