#include <assert.h>
#include <stddef.h>
#include <stdio.h>

ptrdiff_t my_strstr(const char *haystack, const char *needle);

int main(void){
    assert(my_strstr("hello", "he") == 0);
    assert(my_strstr("hello", "ell") == 1);
    assert(my_strstr("hello", "lo") == 3);
    assert(my_strstr("hello", "hello") == 0);
    assert(my_strstr("cat dog cat", "cat") == 0);
    assert(my_strstr("banana", "ana") == 1);
    assert(my_strstr("hello", "l") == 2);
    assert(my_strstr("XBABAB", "ABAB") == 2);
    assert(my_strstr("XXXabc", "abc") == 3);
    assert(my_strstr("ABC ABCDAB ABCDABCDABDE", "ABCDABD") == 15);
    assert(my_strstr("hello", "xyz") == -1);
    assert(my_strstr("hello", "") == -1);
    assert(my_strstr("hi", "hello") == -1);
    assert(my_strstr("", "hi") == -1);
    assert(my_strstr("", "") == -1);
    printf("All tests passed.\n");

    return 0;
}