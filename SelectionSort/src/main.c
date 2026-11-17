#include <stdio.h>
#include "sort.h"
#include "cmp.h"

int main() {
    int numbers[] = {5, 2, 8, 1, 9, 3};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);

    printf("before: ");
    for (size_t i = 0; i < count; i++) printf("%d ", numbers[i]);
    printf("\n");

    selection_sort(numbers, count, sizeof(int), cmp_int);

    printf("after: ");
    for (size_t i = 0; i < count; i++) printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}