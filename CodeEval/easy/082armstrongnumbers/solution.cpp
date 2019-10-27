#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int anum(int x, int digits) {
    int sum = 0;
    while (x > 0) {
        sum += pow(floor(x % 10), digits);
        x /= 10;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    int n;
    while (infile >> n) {
        int y = anum(n, log10(n)+1);
        cout << (y == n ? "True" : "False") << endl;
    }

    return 0;
}
