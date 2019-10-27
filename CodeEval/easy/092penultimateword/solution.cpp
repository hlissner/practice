#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        int n = 0;
        string::iterator start = line.begin();
        string::iterator end = line.end();
        for (auto it = line.end(); it != line.begin(); --it) {
            if (*it == ' ') {
                if (n == 0) {
                    end = it;
                    ++n;
                } else {
                    start = it + 1;
                    break;
                }
            }
        }
        cout << string(start, end) << endl;
    }
    return 0;
}
