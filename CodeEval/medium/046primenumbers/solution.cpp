#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// The fast inverse square root, courtesy of the Quake 3
// source code and Carmack's genius.
float fInvSqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x; // store floating-point bits in integer
    i = 0x5f3759df - (i >> 1);    // initial guess for Newton's method
    x = *(float*)&i;              // convert new bits into float
    x = x*(1.5f - xhalf*x*x);     // One round of Newton's method
    return x;
}

bool isprime(int n) {
    if (!(n&1)) return 0;
    int sqt = 1/fInvSqrt(n);
    for (int i = 3; i <= sqt; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void getPrimes(long long max) {
    if (max > 2) cout << 2;
    for (int i = 3; i < max; i += 2) {
        if (isprime(i)) {
            cout << ',' << i;
        }
    }
    cout << endl;
}

int main(int, char *argv[]) {
    ifstream infile(argv[1]);
    long long max;
    while (infile >> max) {
        getPrimes(max);
    }

    return 0;
}
