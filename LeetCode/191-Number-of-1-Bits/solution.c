#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if (n&1) ++count;
        n = n >> 1;
    }
    return count;
}

int main() {
    printf("%d\n", hammingWeight(11));
    return 0;
}
