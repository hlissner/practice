#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char buf[128];
    while (fgets(buf, 128, f)) {
        bool last = false;
        for (int i = 0; buf[i] != '\0'; i++) {
            if (isalpha(buf[i])) {
                printf("%c", tolower(buf[i]));
                last = true;
            } else {
                if (last) {
                    printf(" ");
                    last = false;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

