#include <stddef.h>
#include <stdlib.h>
#include "sort.h"


static void swap(void *a, void *b, size_t size) {
    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;
    for (size_t i = 0; i < size; i++) {
        unsigned char t = pa[i];
        pa[i] = pb[i];
        pb[i] = t;
    }
}

static void *elem(void *base, size_t i, size_t size) {
    return (char *)base + i * size;
}

static size_t partition(void *base, size_t low, size_t high, size_t size,
                        int (*cmp)(const void *, const void *)) {
    void *pivot = elem(base, high, size); 
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (cmp(elem(base, j, size), pivot) < 0) {
            swap(elem(base, i, size), elem(base, j, size), size);
            i++;
        }
    }
    swap(elem(base, i, size), pivot, size);
    return i;
}

void Quicksort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *)) {
    if (n < 2) return;

    size_t *stack = malloc(2 * n * sizeof(size_t));
    if (stack == NULL) {
        return; 
    }

    size_t top = 0;
    
    stack[top] = 0;
    top++;
    stack[top] = n - 1;
    top++;

    while (top > 0) {
        size_t high = stack[--top];
        size_t low  = stack[--top];

        size_t p = partition(base, low, high, size, cmp);

        if (p > low) {
            stack[top++] = low;
            stack[top++] = p - 1;
        }
    
        if (p + 1 < high) {
            stack[top++] = p + 1;
            stack[top++] = high;
        }
    }
    free(stack);
}