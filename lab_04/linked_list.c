#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct LinkedList {
    Node* head;
};

typedef struct LinkedList List;

bool isEmpty(struct Node* head) {
    return (head == NULL);
}

void insertAtBeginning(List* list, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(list->head)) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
}

void insertAtEnd(List* list, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* active = list->head;

    while (active->next != NULL) {
        active = active->next;
    }

    active->next = newNode;
}

void deleteFromBeginning(List* list) {
    if (isEmpty(list->head)) {
        printf("The list is already empty.\n");
        return;
    }

    Node* toDelete = list->head;
    list->head = list->head->next;
    free(toDelete);

    printf("Deleted from the beginning.\n");
}

void deleteAtEnd(List* list) {
    if (isEmpty(list->head)) {
        printf("The list is already empty.\n");
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        free(current);
        list->head = NULL;
    } else {
        free(current);
        previous->next = NULL;
    }

    printf("Deleted from the end.\n");
}

void printList(List* list) {
    Node* current = list->head;

    if (isEmpty(current)) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice;
    char data;
    List list = {.head = NULL};

    while(1){
        printf("Enter '1' for insertion at the beginning\n"
        "Enter '2' for insertion at the end\n"
        "Enter '3' for deletion form the beginning\n"
        "Enter '4' for deletion at the end\n"
        "Enter '5' to exit the code\n\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to insert:");
                scanf(" %c", &data);
                insertAtBeginning(&list,data);
                printList(&list);
                break;
            case 2:
                printf("Enter the data to insert:");
                scanf(" %c", &data);
                insertAtEnd(&list,data);
                printList(&list);
                break;
            case 3:
                deleteFromBeginning(&list);
                printList(&list);
                break;
            case 4:
                deleteAtEnd(&list);
                printList(&list);
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid choice.");    
        }
        printf("\n");
    }

    return 0;
}
