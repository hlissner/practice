#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        if (line.size() == 0) continue;

        istringstream lhss(line);
        string str;

        if (getline(lhss, str, '|')) {
            int i;
            while (lhss >> i) {
                cout << str[i-1];
            }
            cout << endl;
        }
    }

    return 0;
}
