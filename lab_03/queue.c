#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

int front = -1, rear = -1;
char queue[MAX_SIZE];

int isEmpty(){
    return (front == rear == -1);
}

int isFull(){
    return (rear == MAX_SIZE - 1);
}

void enqueue(char expression){
    if (isFull()){
        printf("Overflow.\n");
        exit(1);
    }

    front = 0;

    if (isEmpty()){
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = expression;
}

void dequeue(){
    if (isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void printQueue (){
    if (isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++){
        printf("%c\t", queue[i]);
    }
    printf("\n");
}

int main(){
    int addNumber, removeNumber;
    printf("Enter the number of elements you want to push into the queue:");
    scanf("%d", &addNumber);

    for (int i = 0; i < addNumber; i++){
        char symbol;
        printf("Enter the element to be pushed into queue: ");
        scanf(" %c", &symbol);
        enqueue(symbol);
        printQueue();
    }

    printf("Enter the number of elements you want to dequeue:");
    scanf("%d", &removeNumber);

    for (int i = 0; i < removeNumber; i++){
        dequeue();
        printQueue();
    }

    return 0;
}
