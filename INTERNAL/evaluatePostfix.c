#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int top = -1;
int stk[MAX_SIZE];

void push(int num) {
    stk[++top] = num;
}

int pop() {
    return stk[top--];
}

int main() {
    char a[MAX_SIZE];
    printf("Enter a valid postfix expression: ");
    if (fgets(a, MAX_SIZE, stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(a);
        if (len > 0 && a[len - 1] == '\n') { //this line of code removes the space/ extra line by replacing them with '\0' or NULL.
            a[len - 1] = '\0';
        }
        for (int i = 0; a[i] != '\0'; i++) {
            char ch = a[i];
            if (ch >= '0' && ch <= '9') {
                push(ch - '0');
            } else {
                int op2 = pop();
                int op1 = pop();
                switch (ch) {
                    case '+': push(op1 + op2); break;
                    case '-': push(op1 - op2); break;
                    case '*': push(op1 * op2); break;
                    case '/': push(op1 / op2); break;
                }
            }
        }
        printf("The result is: %d\n", pop());
    }
    return 0;
}