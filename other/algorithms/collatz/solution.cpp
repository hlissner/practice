#include <iostream>
#include <cstdlib>

using namespace std;

int compute_collatz(int n) {
    int steps = 0;
    while (n != 1) {
        n = n % 2 ? (n * 3) + 1 : n / 2;
        ++steps;
    }
    return steps;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int n = strtol(argv[1], NULL, 10);
        cout << "Steps to " << n << ": " << compute_collatz(n) << endl;
    } else {
        cout << "Usage: " << argv[0] << " [N]" << endl;
        return 1;
    }
    return 0;
}
