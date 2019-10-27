#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <math.h>
using namespace std;

const int MASK[] = {2, 4, 8, 16, 32, 64, 128, 256, 512};

bool isvalid(int n, int digits) {
    int mask = 0;
    while (n >= 1) {
        if (n % digits == 0) return false;

        int mi = (n % 10) - 1;
        if (mi == -1) return false;
        mask = MASK[mi] | mask;
        // If this number has already been visited...
        if ((MASK[mi] & mask) == MASK[mi]) {
            return false;
        }
        n = (int) n / 10;
    }
    return true;
}

bool ismagic(int num) {
    const int digits = log10(num);
    if (num % digits == 0 || !isvalid(num, digits))
        return false;

    int i = 0;
    int visited[5] = {0};
    while (!visited[i]) {
        i = (i + n)
    }

    return true;
}

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        int x, y;
        ss >> x >> y;
        int c = 0;
        for (int i = x; i <= y; ++i) {
            if (ismagic(i)) {
                cout << (c == 0 ? "" : " ") << i;
                ++c;
            }
        }
        cout << (c == 0 ? "-1" : "") << endl;
    }
    return 0;
}
