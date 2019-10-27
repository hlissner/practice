#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        if (line[0] == '\0') continue;

        char last = line[0];
        cout << line[0];
        for (int i = 1; line[i] != '\0'; ++i) {
            if (line[i] != last) {
                last = line[i];
                cout << last;
            }
        }
        cout << endl;
    }
    return 0;
}
