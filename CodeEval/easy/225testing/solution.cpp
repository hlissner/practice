#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string test;
    while (getline(infile, test, '|')) {
        string design;
        getline(infile, design, '\n');

        int bugs = 0;
        for (int i = 0; i < test.size() - 1; ++i) {
            if (test[i] != design[i+1]) ++bugs;
        }

        if (bugs > 6) {
            cout << "Critical";
        } else if (bugs > 4) {
            cout << "High";
        } else if (bugs > 2) {
            cout << "Medium";
        } else if (bugs > 0) {
            cout << "Low";
        } else {
            cout << "Done";
        }
        cout << endl;
    }

    return 0;
}
