#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    int n, x;
    char _;
    while (infile >> x >> _ >> n) {
        int i = n;
        while (i < x) i += n;
        cout << i << endl;
    }
    return 0;
}
