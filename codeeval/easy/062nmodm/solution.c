#include <stdio.h>
int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    int x, y;
    while (fscanf(file, "%d,%d", &x,&y) == 2)
        printf("%d\n", x - y * (int) (x / y));
    return 0;
}
