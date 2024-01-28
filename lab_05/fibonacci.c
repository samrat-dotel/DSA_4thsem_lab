#include<stdio.h>

int fibo(int start, int second, int val){
    if (val == 0) return start;
    if (val == 1) return second;
    return fibo(second, start + second, val - 1);
}

int main(){
    int terms, start, second;

    printf("Enter the number of terms:");
    scanf("%d", &terms);

    printf("Enter the first number of fibonacci series:");
    scanf("%d", &start);

    printf("Enter the second number of fibonacci series:");
    scanf("%d", &second);

    for (int i = 0; i < terms; i++){
        printf("%d\t", fibo(start, second, i));
    }

    return 0;
}
