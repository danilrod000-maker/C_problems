#include <stdio.h>
#include <time.h>

long long iterative(int n) {
    if (n < 0){
        return -1;
    }
    if (n == 0){
        return 0;
    }
    



    long long prev, next;
    prev = 0;
    next = 1;
    for (int i = 2; i <= n;){
        long long temp = prev + next;
        prev = next;
        next = temp;
        i++;
    }
    return next;
}





long long recursive(int n) {
    if (n <= 1){
        return n;
    }
    return recursive(n - 1) + recursive(n - 2);
}



int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0){
    return 1;
    }


    clock_t start1 = clock();
    long long res1 = recursive(n);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1)/CLOCKS_PER_SEC;




    clock_t start2 = clock();
    long long res2 = iterative(n);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    

    printf("Recursive: %d = %lld time: %.20f sec\n", n, res1, time1);
    printf("Iterative: %d = %lld time: %.20f sec\n", n, res2, time2);
    return 0;
}



