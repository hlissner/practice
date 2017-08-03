#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    char buf[128];
    int n, x;
    while (fscanf(f, "%d,%d", &x, &n) == 2) {
        int i = n;
        while (i < x) i += n;
        printf("%d\n", i);
    }
    return 0;
}
