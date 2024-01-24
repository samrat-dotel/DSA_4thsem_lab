#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

int push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return 0;
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed to the stack\n", value);
    return 1;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack->arr[stack->top--];
    printf("%d popped from the stack\n", value);
    return value;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    int numElements;
    printf("Enter the number of elements to be pushed into the stack: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        int value;
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &value);

        if (!push(&myStack, value)) {
            printf("Error pushing element #%d into the stack\n", i + 1);
            break;
        }
    }

    int numElementsToPop;
    printf("\nEnter the number of elements to be popped from the stack: ");
    scanf("%d", &numElementsToPop);

    printf("\nStack contents:\n");
    for (int i = 0; i < numElementsToPop && !isEmpty(&myStack); i++) {
        printf("Top element: %d\n", peek(&myStack));
        printf("%d\n", pop(&myStack));
    }

    printf("Top element: %d\n", peek(&myStack));

    return 0;
}
