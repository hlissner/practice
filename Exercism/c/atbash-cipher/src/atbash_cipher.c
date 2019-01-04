#include "atbash_cipher.h"

#define STRLEN 64

char flipchar(char c) {
    if (isalpha(c))
        return 'z' - (tolower(c) - 'a');
    return c;
}

char* atbash(char* input, int group_size) {
    char* output = (char*) calloc(STRLEN, sizeof(char));
    char* pt = output;
    for (int s = group_size; *input; ++input) {
        if (isalnum(*input)) {
            *(pt++) = flipchar(*input);
            if (--s == 0) {
                *(pt++) = ' ';
                s = group_size;
            }
        }
    }
    if (*(--pt) == ' ') *pt = '\0';
    return output;
}


char* atbash_encode(char* input) { return atbash(input, 5); }
char* atbash_decode(char* input) { return atbash(input, 0); }
