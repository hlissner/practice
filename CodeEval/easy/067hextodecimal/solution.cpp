#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

short value(char c) {
    if (c >= 'a' && c <= 'f') {
        return (c - 'a') + 10;
    } else if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int pows[] = {
        1,
        16,
        256,
        4096,
        65536,
        1048576,
        16777216 // 6
    };

    ifstream infile(argv[1]);

    string str;
    while (infile >> str) {
        auto it = str.begin();
        int len = str.length()-1;

        int n = 0;
        for (int i = 0; i <= len; ++i, ++it) {
            n += value(*it) * pows[len - i];
        }

        cout << n << endl;
    }

    return 0;
}
