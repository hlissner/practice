#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

unordered_map<string, int> prefix = {
    {"nine" , 9},
    {"eight", 8},
    {"seven", 7},
    {"six"  , 6},
    {"five" , 5},
    {"four" , 4},
    {"three", 3},
    {"two"  , 2},
    {"one"  , 1},
    {"zero" , 0}
};

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        if (line.size() == 0) continue;

        istringstream ss(line);
        string str;
        while (getline(ss, str, ';')) {
            cout << prefix[str];
        }
        cout << endl;
    }

    return 0;
}
