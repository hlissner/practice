#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[256];
    while (fgets(line, 256, file)) {
        int i = 0, j = 0;
        while (line[j] != '\0' && line[j] != '\n') {
            while (line[j] != ' ' && line[j] != '\0' && line[j] != '\n' && j < 256) { ++j; }
            char c = line[i];
            line[i] = line[j-1];
            line[j-1] = c;
            i = j+1;
            ++j;
        }

        printf("%s", line);
    }
    return 0;
}
