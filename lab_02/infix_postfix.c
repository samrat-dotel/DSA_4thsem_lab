#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE], infix[MAX_SIZE], postfix[MAX_SIZE];

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(char expression) {
    if (isFull()) {
        printf("Stack is full.");
        exit(1);
    }
    stack[++top] = expression;
}

char pop() {
    if (isEmpty()) {
        printf("Stack is empty.");
        return 0;
    }

    char operator;
    operator = stack[top--];
    return operator;
}

int precedence(char operator) {
    switch (operator) {
        case '^':
        case '*':        // why cannot we write these cases as    case '*' || '/':     ?
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix() {
    char currentSymbol, poppedSymbol;
    int postfixIndex = 0;

    for (int i = 0; i < strlen(infix); i++) {
        currentSymbol = infix[i];

        switch (currentSymbol) {
            case '(':
                push(currentSymbol);
                break;
            case ')':
                while ((poppedSymbol = pop()) != '(')
                    postfix[postfixIndex++] = poppedSymbol;
                break;
            case '*':
            case '/':
            case '+':
            case '-':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(currentSymbol)) {
                    postfix[postfixIndex++] = pop();
                }
                push(currentSymbol);
                break;
            default:
                postfix[postfixIndex++] = currentSymbol;
                break;
        }
    }

    while (!isEmpty()) {
        postfix[postfixIndex++] = pop();
    }
}

void print() {
    printf("The equivalent postfix is:\t");
    for (int i = 0; postfix[i] != '\0'; i++) {
        printf("%c", postfix[i]);
    }
}

int main() {
    printf("Enter the infix expression to be converted into postfix: \t");
    scanf("%s", infix);

    infixToPostfix();

    print();
    return 0;
}
