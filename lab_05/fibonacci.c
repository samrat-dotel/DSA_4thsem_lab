#include<stdio.h>

int fibo(int first, int second, int val){
    if (val == 0) return first;
    if (val == 1) return second;
    return fibo(second, first + second, val - 1);
}

int main(){
    int terms, first, second;

    printf("Enter the number of terms:");
    scanf("%d", &terms);

    printf("Enter the first number of fibonacci series:");
    scanf("%d", &first);

    printf("Enter the second number of fibonacci series:");
    scanf("%d", &second);

    for (int i = 0; i < terms; i++){
        printf("%d\t", fibo(first, second, i));
    }

    return 0;
}
