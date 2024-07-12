#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void push();
void pop();
void peek();
void display();
int stack[SIZE], top = -1;

void push(){
  int x;
  printf("Enter the element: ");
  scanf("%d",&x);

  if(top == SIZE - 1){
    printf("Stack Overflow\n");
  } else {
    top++;
    stack[top] = x;
  }
}

void pop(){
  int item;
  if(top == -1){
    printf("Stack Underflow\n");
  } else {
    item = stack[top];
    top--;
    printf("Popped element is: %d\n", item);
  }
}

void peek(){
  if(top == -1){
    printf("Stack Underflow\n");
  } else {
    printf("The peek element is: %d\n",stack[top]);
  }
}

void display(){
  int i;
  if(top == -1){
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements are:\n");
  for(i=top; i>=0; i--){
    printf("%d\n",stack[i]);
  }
}

int main() {
  int choice;

  while(1) {
    printf("\n\nStack Operations\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        push();
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
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}
