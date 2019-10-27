#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(int, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        int size = line.size();
        bool up = true;
        for (int i = 0; i < size; ++i) {
            if (!isalpha(line[i])) continue;
            if (up) line[i] = toupper(line[i]);
            up = !up;
        }
        cout << line << endl;
    }
    return 0;
}
