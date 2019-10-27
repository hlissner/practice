#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <complex>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> coords;
        stringstream ss(line);

        while (1) {
            short i;
            ss >> i;
            if (ss.eof() || ss.bad()) {
                break;
            } else if (ss.fail()) {
                ss.clear();
                ss.ignore();
            } else {
                coords.push_back(i);
            }
        }

        int x = coords[2] - coords[0],
            y = coords[3] - coords[1];
        cout << sqrt((x * x) + (y * y)) << endl;
    }

    return 0;
}
