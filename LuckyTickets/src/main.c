#include <stdio.h>

int main(void) {
    const long long total = 1000000LL;
    long long sums[28] = {0};
    long long lucky = 0;

    for (int n = 0; n <= 999; ++n) {
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;
        

        sums[d1 + d2 + d3]++;
    }

    
    for (int s = 0; s <= 27; ++s){
        lucky += sums[s]  * sums[s];

    }
    

    double percent = 100.0 * lucky / total;

    printf("lucky tickets: %lld\n", lucky);
    printf("all tickets: %lld\n", total);
    printf("percent of lucky: %.4f%%\n", percent);

    return 0;
}