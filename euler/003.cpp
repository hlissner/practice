// 003: Largest prime factor
// https://projecteuler.net/problem=3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <math.h>

bool isprime(const long long n) {
    for (auto i = 3; i < (long long) sqrt(n)+1; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long pfactor(long long n) {
    auto max = (int) sqrt(n);

    // Make sure we start from an odd number
    if (!(max&1)) --max;

    // Counting backwards (and in steps of 2) through guaranteed odd numbers
    // reduces the number of steps, and starting from sqrt(n) altogether
    // significantly reduces the number of steps to find the greatest prime
    // factor.
    for (auto i = max; i > 3; i -= 2) {
        if (n % i == 0 && isprime(i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::cout << pfactor(600851475143LL) << std::endl;
    return 0;
}
