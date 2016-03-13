#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        if (line.size() == 0) continue;

        auto y = line.end();
        auto begin = line.begin();
        while (begin != y && *begin == ' ') ++begin;
        if (begin == y) continue;
        
        while (*y == ' ') { --y; }
        auto x = line.end();
        
        while (x != begin) {
            while (x != begin && *(x-1) != ' ') --x;
            bool atstart = x == begin;
            cout << string(x, y) << (atstart ? "" : " ");
            if (!atstart) {
                y = x-1;
                --x;
            }
        }
        cout << endl;
    }

    return 0;
}