#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

int div(int *n, int value) {
    if (*n > value) {
        int m = floor(*n / value);
        *n %= value;
        cout << *n << " ";
        return m;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    deque<pair<char, int>> roman = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };

    ifstream infile(argv[1]);
    int n;
    while (infile >> n) {
        for (const auto kv : roman) {
            cout << kv.first << ' ';
        }
        cout << endl;
        int m = div(&n, 1000),
            d = div(&n, 500),
            c = div(&n, 100),
            l = div(&n, 50),
            x = div(&n, 10),
            v = div(&n, 5),
            i = div(&n, 1);

        cout << n << endl;
    }
    return 0;
}
