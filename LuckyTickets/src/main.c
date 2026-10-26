#include <stdio.h>

int main(void) {
    const int total = 1000000;
    int lucky = 0;
    
    int sum_counts[28] = {0};

    for (int n = 0; n <= 999; ++n) {
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;

        int sum = d1 + d2 + d3;
        sum_counts[sum]++;
    }

    for (int s = 0; s <= 27; ++s) {
        lucky += sum_counts[s] * sum_counts[s];
    }

    double percent = 100.0 * lucky / total;

    printf("lucky tickets: %d\n", lucky);
    printf("all tickets: %d\n", total);
    printf("percent of lucky: %.4f%%\n", percent);

    return 0;
}
