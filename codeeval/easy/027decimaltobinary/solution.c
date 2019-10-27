#include <stdio.h>

void print_bit(const int n) {
    if (n <= 0) return;
    print_bit(n / 2);
    printf("%d", n & 1);
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    int n;
    while (fscanf(f, "%d", &n) == 1) {
        if (n == 0) {
            printf("0\n");
        } else {
            print_bit(n);
            printf("\n");
        }
    }
    return 0;
}
