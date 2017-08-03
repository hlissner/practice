#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 64
#define MAXLEN 256

int complen(const void* a, const void* b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);
    return (fa < fb) - (fa > fb);
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    char nbuf[8];
    if (fgets(nbuf, 8, file) == NULL) {
        return 1;
    }
    int n = atoi(nbuf);

    int i = 0;
    char lines[ROWS][MAXLEN];
    char buf[MAXLEN];
    while (fgets(buf, MAXLEN, file)) {
        strncpy(lines[i++], buf, MAXLEN);
    }

    qsort(lines, ROWS, MAXLEN, complen);
    for (int i = 0; i < n; ++i) {
        printf("%s", lines[i]);
    }

    return 0;
}