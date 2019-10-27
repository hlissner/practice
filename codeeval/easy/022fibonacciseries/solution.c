#include <stdio.h>
#include <math.h>

#define FIBP sqrt(5)
#define FIBP_A (1 + FIBP) / 2
#define FIBP_B (1 - FIBP) / 2

long long fib(int n) {
    return floor((pow(FIBP_A, n+1) - pow(FIBP_B, n+1)) / FIBP);
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    int i;
    while (fscanf(f, "%d", &i) == 1) {
        printf("%lld\n", fib(i-1));
    }
    return 0;
}
