#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[512];
    while (fgets(line, 512, f)) {
        int size = 0;
        int x, offset;
        int n[128];
        char *lpt = line;
        while (sscanf(lpt, "%d%n", &x, &offset) == 1 && size < 128) {
            n[size++] = x;
            lpt += offset;
        }

        for (int i = 0; size > 0; ++i, --size) {
            if ((i&1) == 0) printf("%d ", n[size-1]);
        }
        printf("\n");
    }
    return 0;
}
