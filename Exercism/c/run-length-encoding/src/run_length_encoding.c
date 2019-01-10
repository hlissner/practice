#include "run_length_encoding.h"

#define BUFFER_SIZE 128

int nextcount(char c, const char* input) {
    if (c == *input)
        return nextcount(c, ++input) + 1;
    return 0;
}

char* encode(const char* input) {
    char* output = (char*) malloc(BUFFER_SIZE);
    char ch;
    int n, i = 0;
    while ((ch = *input) != '\0') {
        if ((n = nextcount(ch, input)) > 0) {
            i += n > 1
                ? sprintf(output + i, "%d%c", n, ch)
                : sprintf(output + i, "%c", ch);
        }
        ch = *input;
        input += n;
    }
    return output;
}

char* decode(const char* input) {
    char* output = (char*) malloc(BUFFER_SIZE);
    char* out = output;
    while (*input != '\0') {
        char ch;
        int n = 1, p = 1;
        isdigit(*input)
            ? sscanf(input, "%d%c%n", &n, &ch, &p)
            : sscanf(input, "%c", &ch);
        input += p;
        while (n--) *(out++) = ch;
    }
    *out = '\0';
    return output;
}
