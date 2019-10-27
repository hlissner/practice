#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char buf[256];
    while (fgets(buf, 256, f)) {
        int i = 0;
        int j = strlen(buf) - 2;
        if (j == 0) continue;

        while (buf[i+1] != ',') ++i;
        int jBeg = i + 2;

        bool atEnd = true;

        if (i+1 < (j - jBeg)+1) {
            atEnd = false;
        } else {
            while (i >= 0 && j >= jBeg) {
                if (buf[i] != buf[j]) {
                    atEnd = false;
                    break;
                }
                --i; --j;
            }
        }
        printf("%d\n", (atEnd ? 1 : 0));
    }
    return 0;
}
