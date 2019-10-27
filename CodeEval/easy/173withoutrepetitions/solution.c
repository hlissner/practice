#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[1024];
    while (fgets(line, 1024, f)) {
        if (line[0] == '\0') continue;

        char last = line[0];
        printf("%c", line[0]);
        for (int i = 1; line[i] != '\0'; ++i) {
            if (line[i] != last) {
                last = line[i];
                printf("%c", last);
            }
        }
        printf("\n");
    }
    return 0;
}

