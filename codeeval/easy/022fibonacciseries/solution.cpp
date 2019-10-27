#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define FIBP sqrt(5)
#define FIBP_A (1 + FIBP) / 2
#define FIBP_B (1 - FIBP) / 2

long long fib(int n) {
    return floor((pow(FIBP_A, n+1) - pow(FIBP_B, n+1)) / FIBP);
}

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    long long i;
    while (infile >> i)
        cout << fib(i-1) << endl;
    return 0;
}
