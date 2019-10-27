#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int add(char *str, int *arr) {
    int i = 0, n, offset;
    while (sscanf(str, "%d%n", &n, &offset) == 1) {
        arr[i] = n;
        str += offset + 1;
        ++i;
    }
    return i;
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[128];
    while (fgets(line, 128, f)) {
        if (line[0] == '\n') continue;

        int delim = 0;
        while (line[delim++] != ';');
        line[delim-1] = '\0';

        char lhs[128] = "", rhs[128] = "";
        strcpy(lhs, line);
        strcpy(rhs, line + delim);

        int a[32] = {0}, b[32] = {0};
        char *lp = lhs, *rp = rhs;
        int alen = add(lp, a),
            blen = add(rp, b);

        bool found = false;
        for (int i = 0; i < alen; ++i) {
            for (int j = 0; j < blen; ++j) {
                if (a[i] == b[j]) {
                    printf(found ? ",%d" : "%d", b[j]);
                    found = true;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
