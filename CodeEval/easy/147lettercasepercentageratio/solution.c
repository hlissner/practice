#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[64];
    while (fgets(line, 64, f)) {
        double up = 0, down = 0;
        int size = strlen(line);
        for (int i = 0; i < size; ++i) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                ++down;
            } else if (line[i] >= 'A' && line[i] <= 'Z') {
                ++up;
            }
        }
        if (line[size-1] == '\n')
            --size;

        float downp = (down / size) * 100;
        float upp   = (up / size) * 100;

        printf("lowercase: %.2f uppercase: %.2f\n", downp, upp);
    }
    return 0;
}
