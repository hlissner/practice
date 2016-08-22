// 003: Largest prime factor - C++
// https://projecteuler.net/problem=3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath>

using namespace std;

bool isprime(long long n) {
    if (n <= 3) return true;
    if (!(n&1)) return false; // even numbers gtfo
    for (auto i = 3; i < (long long) sqrt(n)+1; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * My first attempt using a method I thought up in 2005 for a similar problem.
 * While reasonably fast, the primality test wastes a lot of time retesting
 * numbers. Perhaps use a sieve?
 */
long long pfactor(long long n) {
    auto max = (int) sqrt(n);

    // Make sure we start from an odd number
    if (!(max&1)) --max;

    // Counting backwards (and in steps of 2) through odd numbers from sqrt(n)
    // reduces the number of steps to find the greatest prime factor.
    for (auto i = max; i >= 3; i -= 2) {
        if (n % i == 0 && isprime(i)) {
            return i;
        }
    }

    // Even number fallback
    if (!(n&1)) return 2;
    return -1;
}

/**
 * Second attempt, written in 2016; which significantly cuts down on iterations
 * using division.
 */
long long pfactor2(long long n) {
    int factor = 3,
        last = 1;

    // Make sure we start from an odd number. Allows increments of 2 in later
    // factor checks.
    if (!(n&1)) {
        do { n /= 2; } while (!(n&1));
        last = 2;
    }

    // The largest possible factor
    auto max = sqrt(n);

    while (n > 1 && factor <= max) {
        if (n % factor == 0) {
            do { n /= factor; } while (n % factor == 0);
            last = factor;
            max = sqrt(n);
        }
        factor += 2;
    }

    return n == 1 ? last : n;
}

//
int main(int argc, char *argv[]) {
    auto n = 600851475143L;
    cout << pfactor(n) << endl;
    cout << pfactor2(n) << endl;
    return 0;
}
