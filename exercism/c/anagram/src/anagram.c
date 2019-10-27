#include "anagram.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp_char (const void* a, const void *b) {
    return *(char*)a - *(char*)b;
}

char* str_copy_lower (char* src) {
    char* dest = malloc(sizeof(char) * MAX_STR_LEN);
    for (int i = 0; src[i] != '\0'; ++i) {
        dest[i] = tolower(src[i]);
    }
    return dest;
}

int is_anagram_of(char* str, char* other) {
    int len  = strlen(str);
    if (len != (int) strlen(other))
        return 0;

    char* _str   = str_copy_lower(str);
    char* _other = str_copy_lower(other);
    int result = 0;
    if (strncmp(_str, _other, MAX_STR_LEN)) {
        qsort(_str,   len, sizeof(char), cmp_char);
        qsort(_other, len, sizeof(char), cmp_char);

        result = strncmp(_str, _other, MAX_STR_LEN) == 0;
    }

    free(_str);
    free(_other);
    return result;
}

struct Vector anagrams_for(char* str, struct Vector inputs) {
    struct Vector result;
    result.vec = (char(*)[MAX_STR_LEN]) malloc(sizeof(char) * MAX_STR_LEN * 32);
    result.size = 0;

    for (int i = 0; i < inputs.size; ++i) {
        if (is_anagram_of(str, inputs.vec[i])) {
            strncpy(result.vec[result.size++], inputs.vec[i], MAX_STR_LEN);
        }
    }

    return result;
}

