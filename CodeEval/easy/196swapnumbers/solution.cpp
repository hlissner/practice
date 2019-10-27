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
        while (getline(ss, word, ' ')) {
            int end = word.size()-1;
            char tmp = word[0];
            word[0] = word[end];
            word[end] = tmp;

            cout << word << ' ';
        }
        cout << endl;
    }

    return 0;
}
