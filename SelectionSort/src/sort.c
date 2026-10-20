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

void selection_sort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *)) {
    if (n < 2) {
        return;
    }

    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_elem_ind = i;

        for (size_t j = i + 1; j < n; ++j) {
            void *min_elem = (char *)base + min_elem_ind * size;
            void *cur_elem = (char *)base + j * size;

            if (cmp(min_elem, cur_elem) > 0) {
                min_elem_ind = j;
            }
        }

        if (min_elem_ind != i) {
            swap((char *)base + i * size,
                 (char *)base + min_elem_ind * size,
                 size);
        }
    }
}