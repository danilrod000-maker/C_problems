#include <stdio.h>


int iterative(void) {

    int place;
    printf("Enter number: ");
    if (scanf("%d", &place) != 1 || place <= 0) {
        printf("Input error\n");
        return 1;
    }


    int prev = 0, next = 1;
    for (int i = 1; i < place; i++) {
        int temp = prev + next;
        prev = next;
        next = temp;
    }

    printf("%d\n", prev);
    return 0;
}




long long recursive(int n){
    if (n <= 1);
    return recursive(n-1) + recursive(n-2);
}


int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    printf("Recursive: F(%d) = %lld\n", n, recursive(n));
    printf("Iterative: F(%d) = %lld\n", n, iterative(n));
    return 0;
}



