#include <iostream>
#include <math.h>

// O(log n)-ish and (theoretically) imprecise solution
long long fast_fib(int n) {
    float p = sqrt(5);
    return floor((pow((1 + p) / 2, n+1) - pow((1 - p) / 2, n+1)) / p);
}

// O(n^2) solution
int slow_fib(int n) {
    if (n <= 1) return 1;
    return slow_fib(n-1) + slow_fib(n-2);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int max = atoi(argv[1]);

        if (max > 92) {
            max = 92;
            std::cout << "92+ fibs exceed a long long's capacity. Capping at 92." << std::endl;
            // TODO: implement bignum?
        }

        for (int i = 0; i < max; i++) {
            std::cout << fast_fib(i) << std::endl;
        }
    } else {
        std::cout << "Usage: " << argv[0] << " [amount]" << std::endl;
        return 1;
    }

    return 0;
}
