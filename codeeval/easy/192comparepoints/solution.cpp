#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        istringstream ss(line);

        int o, p;
        int q, r;
        ss >> o >> p;
        ss >> q >> r;

        int x = q - o,
            y = r - p;

        if (x == 0 && y == 0) {
            cout << "here";
        } else {
            if (y > 0) cout << 'N';
            else if (y < 0) cout << 'S';
            if (x > 0) cout << 'E';
            else if (x < 0) cout << 'W';
        }
        cout << endl;
    }
    return 0;
}
