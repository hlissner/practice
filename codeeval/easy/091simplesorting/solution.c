#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
   return (*(float*)b < *(float*)a);
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char line[256];
    while (fgets(line, 256, f)) {
        float n, set[64];
        int offset;

        int i = 0;
        char *lpt = line;
        while (sscanf(lpt, "%f%n", &n, &offset) == 1) {
            set[i++] = n;
            lpt += offset;
        }

        qsort(set, i, sizeof(float), comp);

        for (int j = 0; j < i; ++j)
            printf("%.3f ", set[j]);
        printf("\n");
    }

    return 0;
}
