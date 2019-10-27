#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[512];
    while (fgets(line, 512, f)) {
        int n = 0, offset;
        int last = -1;
        short p = 0;
        char *lpt = line;
        while (sscanf(lpt, "%d%n", &n, &offset) == 1) {
            if (last == -1 || n != last) {
                printf(p ? ",%d" : "%d", n);
                p = 1;
                last = n;
            }
            lpt += offset + 1;
        }
        printf("\n");
        memset(line, 0, strlen(line));
    }
    return 0;
}
