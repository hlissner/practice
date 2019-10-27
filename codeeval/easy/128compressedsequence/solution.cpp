#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        istringstream ss(line);

        int n, last = -1, count = 0;
        while (ss >> n) {
            if (last != -1 && last != n) {
                cout << count << ' ' << last << ' ';
                count = 0;
            }
            ++count;
            last = n;
        }
        cout << count << ' ' << last << ' ';
        cout << endl;
    }
    return 0;
}
