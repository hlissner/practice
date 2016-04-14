#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char buf[64];
    while (fgets(buf, 64, f)) {
        int len = strlen(buf);
        for (int i = 0; i < len; ++i) {
            char c = buf[i];
            if (isalpha(c)) {
                buf[i] = isupper(c) ? tolower(c) : toupper(c);
            }
        }
        printf("%s", buf);
    }
    return 0;
}
