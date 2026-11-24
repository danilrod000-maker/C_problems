#ifndef SORT_H
#define SORT_H
#include <stddef.h>
void quicksort(void *base, size_t n, size_t size,
               int (*cmp)(const void *, const void *));

#endif