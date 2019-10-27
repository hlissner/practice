#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char buf[128];
    while (fgets(buf, 128, f)) {
        int n, offset;
        char *lpt = buf;
        while (sscanf(lpt, "%d%n", &n, &offset) == 1) {
            printf("%d ", n);
            lpt += offset;
        }
        printf("\n");
    }
    return 0;
}


