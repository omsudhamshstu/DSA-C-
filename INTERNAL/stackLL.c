#include <stdio.h>
#include <stdlib.h>

void push(int x);
void pop();
void peek();
void display();

struct stack {
  int data;
  struct stack *next;
} * top, *new_node;

void push(int x) {
  new_node = (struct stack *)malloc(sizeof(struct stack));
  new_node->data = x;
  new_node->next = top;
  top = new_node;
}

void pop() {
  if (top == NULL) {
    printf("Stack Underflow!\n");
  } else {
    struct stack *temp = top;
    printf("Popped element is: %d\n", top->data);
    top = top->next;
    free(temp);
  }
}

void peek() {
  if (top == NULL) {
    printf("Stack is EMPTY!\n");
  } else {
    printf("Top element is: %d\n", top->data);
  }
}

void display() {
  struct stack *temp = top;
  if (top == NULL) {
    printf("Stack is EMPTY!\n");
  } else {
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int ch, value;

  while (1) {
    printf("\nStack Operations:\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter value to push: ");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice! Please enter a number between 1 and 5.\n");
    }
  }

  return 0;
}
