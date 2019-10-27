#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        string src, sub;
        auto it = line.begin();
        while (*it != ',') ++it;
        src = string(line.begin(), it);
        sub = string(it+2, line.end());

        auto x = src.begin();
        auto y = sub.begin();

        while (x != src.end()) {
            bool found = false;
            do {
                if (*x == *y) {
                    found = true;
                    break;
                }
                ++y;
            }
            while (y != sub.end());
            if (!found) cout << *x;

            ++x;
            y = sub.begin();
        }
        cout << endl;
    }

    return 0;
}
