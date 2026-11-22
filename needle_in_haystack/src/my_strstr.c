#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "my_strstr.h"

static void build_good_suffix(const char *needle, size_t n,
                              size_t *shift, size_t *bpos)
{
    size_t i = n, j = n + 1;
    bpos[i] = j;

    while (i > 0) {
        while (j <= n && needle[i - 1] != needle[j - 1]) {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = bpos[j];
        }
        --i;
        --j;
        bpos[i] = j;
    }

    j = bpos[0];
    for (i = 0; i <= n; ++i) {
        if (shift[i] == 0)
            shift[i] = j;
        if (i == j)
            j = bpos[j];
    }
}

ptrdiff_t my_strstr(const char *haystack, const char *needle){
    size_t text_len   = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len == 0 || needle_len > text_len)
        return (ptrdiff_t)-1;

    size_t last[256] = {0};
    for (size_t i = 0; i < needle_len; ++i)
        last[(unsigned char)needle[i]] = i + 1;

    size_t *good_shifts = calloc(needle_len + 1, sizeof *good_shifts);
    if (good_shifts != NULL) {
        size_t *border = calloc(needle_len + 1, sizeof *border);
        if (border != NULL) {
            build_good_suffix(needle, needle_len, good_shifts, border);
            free(border);
        } else {
            free(good_shifts);
            good_shifts = NULL;
        }
    }

    size_t pos = 0;
    while (pos <= text_len - needle_len) {
        size_t j = needle_len;
        while (j > 0 && haystack[pos + j - 1] == needle[j - 1])
            --j;

        if (j == 0) {
            free(good_shifts);
            return (ptrdiff_t)pos;
        }
        unsigned char bad_char = (unsigned char)haystack[pos + j - 1];
        size_t step = (j > last[bad_char]) ? (j - last[bad_char]) : 1;
        if (good_shifts != NULL && good_shifts[j] > step)
            step = good_shifts[j];
        pos += step;
    }

    free(good_shifts);
    return (ptrdiff_t)-1;
}