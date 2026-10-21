#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include "sort.h"
#include "cmp.h"
#include "test.h"

void run_all_tests(void) {
    printf("Running tests\n");

    double arr_double[] = {3.14, -0.5, 2.71, 0.0};
    size_t n_double = sizeof(arr_double) / sizeof(arr_double[0]);
    selection_sort(arr_double, n_double, sizeof(double), cmp_double);
    assert(arr_double[0] == -0.5);
    assert(arr_double[3] == 3.14);

    const char *arr_str[] = {"cherry", "banana", "pear", "apple"};
    size_t n_str = sizeof(arr_str) / sizeof(arr_str[0]);
    selection_sort(arr_str, n_str, sizeof(char *), cmp_str);
    assert(strcmp(arr_str[0], "apple") == 0);
    assert(strcmp(arr_str[1], "banana") == 0);
    assert(strcmp(arr_str[2], "cherry") == 0);
    assert(strcmp(arr_str[3], "pear") == 0);

    int empty_arr[] = {0};
    selection_sort(empty_arr, 0, sizeof(int), cmp_int);

    int single_arr[] = {42};
    selection_sort(single_arr, 1, sizeof(int), cmp_int);
    assert(single_arr[0] == 42);

    int duplicate_arr[] = {2, 3, 2, 1, 2};
    selection_sort(duplicate_arr, 5, sizeof(int), cmp_int);
    assert(duplicate_arr[0] == 1);
    assert(duplicate_arr[1] == 2);
    assert(duplicate_arr[2] == 2);
    assert(duplicate_arr[3] == 2);
    assert(duplicate_arr[4] == 3);

    printf("All tests passed\n\n");
}


