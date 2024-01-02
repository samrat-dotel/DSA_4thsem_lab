#include<stdio.h>

void insertion(char arr[], int size) {
    int position, value;
    printf("Enter the position in which you want to insert the value:");
    scanf("%d", &position);
    printf("Enter the value you want to insert:");
    scanf(" %c", &value);

    for (int i = size - 1; i >= position; i--) 
        arr[i + 1] = arr[i];
    arr[position] = value;
    size++;

    for (int i = 0; i < size; i++) 
        printf("%c ", arr[i]);
}

void deletion(char arr[], int size) {
    int position;
    printf("Enter the position from which you want to delete the value:");
    scanf("%d", &position);

    for (int i = position; i < size - 1; i++) 
        arr[i] = arr[i + 1];
    size--;

    for (int i = 0; i < size; i++) 
        printf("%c ", arr[i]);
    
}

int main() {
    int size, a;
    printf("Enter the size of array:");
    scanf("%d", &size);
    char arr[size];
    printf("Enter the array:");

    for (int i = 0; i < size; i++) {
        scanf(" %c", &arr[i]);
    }

    printf("Enter 1 for insertion and 2 for deletion:");
    scanf("%d", &a);
    switch (a) {
        case 1:
            insertion(arr, size);
            break;
        case 2:
            deletion(arr, size);
            break;
        default:
            break;
    }
}