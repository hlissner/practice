#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[128];
    while (fgets(line, 128, f)) {
        int end = strlen(line) - 1;
        int len = 1;
        for (int i = end; i >= 0; --i, ++len) {
            if (i == 0 || line[i-1] == ' ') {
                printf("%.*s ",
                       // Make sure newlines aren't included
                       (line[i + len-1] == '\n' ? len-1 : len),
                       line + i);
                len = 0;
                --i; // skip whitespace
            }
        }
        printf("\n");
    }

    return 0;
}
