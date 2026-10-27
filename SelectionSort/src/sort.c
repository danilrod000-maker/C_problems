#include <stdio.h>
#include <stddef.h>

static void swap(void *a, void *b, size_t size) {
    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;

    for (size_t i = 0; i < size; ++i) {
        unsigned char tmp = pa[i];
        pa[i] = pb[i];
        pb[i] = tmp;
    }
}

void selection_sort(void *base, size_t n, size_t size,
                    int (*cmp)(const void *, const void *)) {
    if (n < 2) {
        return;
    }

    char *base_ptr = (char *)base;

    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_elem_ind = i;
        char *min_elem = base_ptr + i * size;
        char *cur_elem = base_ptr + (i + 1) * size;

        for (size_t j = i + 1; j < n; ++j, cur_elem += size) {
            if (cmp(min_elem, cur_elem) > 0) {
                min_elem_ind = j;
                min_elem = cur_elem;
            }
        }

        if (min_elem_ind != i) {
            swap(base_ptr + i * size, min_elem, size);
        }
    }
}