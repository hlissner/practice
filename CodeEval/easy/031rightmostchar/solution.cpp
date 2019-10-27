#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        unordered_map<char, int> src;
        char sub;

        int i = 0;
        auto it = line.begin();
        while (*it != ',') {
            src[*it] = i;
            ++it;
            ++i;
        }
        ++it;
        if (!(sub = *it)) {
            cout << -1 << endl;
            continue;
        }

        auto search = src.find(sub);
        if (search != src.end()) {
            cout << src[sub] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
