#include "isogram.h"

bool is_isogram(const char str[]) {
    if (str == NULL) {
        return false;
    }

    char found[26] = {0};
    for (char c; (c = *str); ++str) {
        if (isalpha(c) && found[tolower(c) - 'a']++) {
            return false;
        }
    }
    return true;
}
