#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[128];
    while (fgets(line, 128, f)) {
        char *lpt = line;
        char chars[64];

        char c;
        int n, offset, size = 0;

        while (sscanf(lpt, "%c%n", &c, &offset)) {
            if (c >= '0' && c <= '9') {
                sscanf(lpt, "%d", &n);
                break;
            } else if (!isalpha(c)) {
                lpt += offset;
                continue;
            }

            lpt += offset;
            chars[size] = c;
            ++size;
        }

        int i = (size - 1) - (n - 1);
        if (i < 0) continue;
        printf("%c\n", (i < 0 ? ' ' : chars[i]));
    }
    return 0;
}
