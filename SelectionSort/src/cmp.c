#include <string.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return  1;
    return 0;
}

int cmp_double(const void *a, const void *b) {
    double x = *(const double *)a;
    double y = *(const double *)b;

    if (x < y) return -1;
    if (x > y) return  1;
    return 0;
}

int cmp_str(const void *a, const void *b) {
    const char *s1 = *(const char * const *)a;
    const char *s2 = *(const char * const *)b;

    if (strcmp(s1, s2) < 0) return -1;
    if (strcmp(s1, s2) > 0) return  1;
    return 0;
}

int cmp_str_array(const void *a, const void *b) {
    const char *s1 = (const char *)a;
    const char *s2 = (const char *)b;

    if (strcmp(s1, s2) < 0) return -1;
    if (strcmp(s1, s2) > 0) return  1;
    return 0;
}