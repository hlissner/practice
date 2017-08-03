#include <stdio.h>
#include <math.h>

int isprime(int n) {
    if (!(n&1)) return 0;
    for (int i = 3; i <= (int) sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

const int primes(int n) {
    int sum = 2;
    for (int i = 3; n > 1; i += 2) {
        if (isprime(i)) {
            sum += i;
            --n;
        }
    }
    return sum;
}

int main(int argc, char *argv[]) {
    printf("%i\n", primes(1000));
    return 0;
}
