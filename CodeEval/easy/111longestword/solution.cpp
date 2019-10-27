#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        istringstream ss(line);
        string word, longest;
        while (getline(ss, word, ' ')) {
            if (word.size() > longest.size()) longest = word;
        }
        cout << longest << endl;
    }

    return 0;
}
