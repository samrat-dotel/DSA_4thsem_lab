#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char locket[1000][100];

    for (int i = 0; i < n; i++) {
        scanf("%s", locket[i]);
    }

    for (int i = 0; i < n; i++) {
        int hasMirror = 0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                char reversedElement[20];
                strcpy(reversedElement, locket[j]);
                reverseString(reversedElement);

                if (strcmp(locket[i], reversedElement) == 0) {
                    hasMirror = 1;
                    break;
                }
            }
        }

        if (!hasMirror) {
            printf("%s\n", locket[i]);
            break;
        }
    }

    return 0;
}
