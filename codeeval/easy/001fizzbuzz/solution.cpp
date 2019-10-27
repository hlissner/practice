#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    int a, b;
    long long max;
    while (infile >> a >> b >> max) {
        for (int i = 1; i <= max; ++i) {
            if (i % a == 0) cout << "F";
            if (i % b == 0) cout << "B";
            if (i % a != 0 && i % b != 0) cout << i;
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
