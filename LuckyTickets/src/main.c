#include <stdio.h>

int main(void) {
    const unsigned int total = 1000000;
    unsigned int lucky = 0;
    int sum_counts[28] = {0};

    for (int n = 0; n <= 999; ++n) {
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;

        int sum = d1 + d2 + d3;
        sum_counts[sum]++;
    }

    for (int s = 0; s <= 13; ++s) {
        lucky += 2 * sum_counts[s] * sum_counts[s];
    }
    float percent = 100.0 * lucky / total;

    printf("lucky tickets: %u\n", lucky);
    printf("all tickets: %u\n", total);
    printf("percent of lucky: %.4f%%\n", percent);

    return 0;
}