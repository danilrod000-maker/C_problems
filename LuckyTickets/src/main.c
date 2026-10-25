#include <stdio.h>

int main(void) {
    const long long total = 1000000LL;
    long long lucky = 0;

    for (int n = 0; n <= 999999; ++n) {
        int d1 = (n / 100000) % 10;
        int d2 = (n / 10000) % 10;
        int d3 = (n / 1000) % 10;
        int d4 = (n / 100) % 10;
        int d5 = (n / 10) % 10;
        int d6 = n % 10;

        int sum1 = d1 + d2 + d3;
        int sum2 = d4 + d5 + d6;

        if (sum1 == sum2) {
            lucky++;
        }
    }

    double percent = 100.0 * lucky / total;

    printf("lucky tickets: %lld\n", lucky);
    printf("all tickets: %lld\n", total);
    printf("percent of lucky: %.4f%%\n", percent);

    return 0;
}