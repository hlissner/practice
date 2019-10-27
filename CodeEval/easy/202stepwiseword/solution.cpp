#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        istringstream ss(line);
        string word;
        string longest;
        while (getline(ss, word, ' ')) {
            if (word.size() > longest.size()) {
                longest = word;
            }
        }

        for (int i = 0; i < longest.size(); ++i) {
            for (int j = 0; j != i; ++j) {
                cout << '*';
            }
            cout << longest[i] << ' ';
        }

        cout << endl;
    }
    return 0;
}
