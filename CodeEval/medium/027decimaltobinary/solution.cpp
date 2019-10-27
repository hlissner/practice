#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    int n;
    while (infile >> n) {
        if (n == 0) {
            cout << 0 << endl;
        } else {
            string out;
            out.reserve(32);
            while (n != 0) {
                int r = n % 2;
                out += r + '0';
                n /= 2;
            }
            reverse(out.begin(), out.end());
            cout << out << endl;
        }
    }
    return 0;
}
