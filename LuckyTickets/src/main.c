#include <stdio.h>

int main(void) {
    const size_t total = 1000000;
    size_t lucky = 0;
    int sum_counts[14] = {0};

    for (int n = 0; n <= 999; ++n) {
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;

        int sum = d1 + d2 + d3;
        if (sum <= 13){
            sum_counts[sum]++;
        }
    }

    for (int s = 0; s <= 13; ++s) {
        lucky += 2 * (size_t)sum_counts[s] * sum_counts[s];
    }

    double percent = 100.0 * lucky / total;

    printf("lucky tickets: %zu\n", lucky);
    printf("all tickets: %zu\n", total);
    printf("percent of lucky: %.4f%%\n", percent);

    return 0;
}