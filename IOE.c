#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int unsortedElement = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            unsortedElement = arr[i - 2];
            break;
        }

        else if (arr[i] == arr[i+1])
        {
            break;
        }
    }

    if (unsortedElement == 0) {
        printf("0\n");
    } else {
        printf("%d\n", unsortedElement);
    }

    return 0;
}