// 003: Largest prime factor
// https://projecteuler.net/problem=3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath>

using namespace std;

bool isprime(const long long n) {
    if (n <= 3) return true;
    if (!(n&1)) return false; // even numbers gtfo
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
    for (auto i = max; i >= 3; i -= 2) {
        if (n % i == 0 && isprime(i)) {
            return i;
        }
    }

    // Even number fallback
    if (!(n&1)) return 2;
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        long long n = strtol(argv[1], NULL, 10);
        cout << pfactor(n) << endl;
    } else {
        cout << "Usage: " << argv[0] << " [N]" << endl;
        return 1;
    }
    return 0;
}
