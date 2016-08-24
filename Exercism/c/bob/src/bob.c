#include "bob.h"

int is_addressing(const char* input, int len) {
    return len == 0;
}

int is_questioning(const char* input, int len) {
    return input[len-1] == '?';
}

int is_shouting(const char* input, int len) {
    int hasUpper = 0;
    for (int i = 0; i < len; ++i) {
        const char c = (input)[i];
        if (!isalpha(c)) continue;
        // The speaker is shouting if all alphabetical characters are uppercase.
        if (isupper(c))
            hasUpper = 1;
        // Even one lower-case character indicates the speaker isn't shouting
        if (c >= 'a' && c <= 'z')
            return 0;
    }
    return hasUpper;
}

//
const char *hey_bob(const char* statement) {
    // Make a copy; don't mutate original
    char input[128];
    strncpy(input, statement, 128);

    if (input[0] != '\0') {
        // rtrim input
        int i = strlen(input)-1;
        for (; i > 0; --i) {
            if (input[i] != ' ') {
                input[i+1] = '\0';
                break;
            }
        }
        // Handle input that is all spaces
        if (i == 0) input[0] = '\0';
    }

    const int len = strlen(input);
    if (is_addressing(input, len)) {
        return "Fine. Be that way!";
    } else if (is_shouting(input, len)) {
        return "Whoa, chill out!";
    } else if (is_questioning(input, len)) {
        return "Sure.";
    }

    return "Whatever.";
}
