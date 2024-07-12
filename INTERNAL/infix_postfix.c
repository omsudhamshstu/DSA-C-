#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int top = -1;
char stk[MAX_SIZE];

void push(char ch) {
    stk[++top] = ch;
}

char pop() {
    return stk[top--];
}

int priority(char ch) {
    switch (ch) {
        case '/': return 3;
        case '*': return 4;
        case '+': return 1;
        case '-': return 2;
        default: return 0;
    }
}

int main() {
    char a[MAX_SIZE];
    printf("Enter a valid infix expression: ");
    fgets(a, MAX_SIZE, stdin);
    printf("Your postfix expression is: ");

    for (int i = 0; a[i] != '\0'; i++) {
        char ch = a[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            printf("%c", ch);
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((ch = pop()) != '(') {
                printf("%c", ch);
            }
        } else {
            while (top >= 0 && priority(stk[top]) >= priority(ch)) {
                printf("%c", pop());
            }
            push(ch);
        }
    }
    while (top >= 0) {
        printf("%c", pop());
    }
    return 0;
}