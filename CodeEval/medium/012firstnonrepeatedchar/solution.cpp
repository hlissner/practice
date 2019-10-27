#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        char c;
        for (int i = 0; i < line.size(); ++i) {
            bool isRepeated = false;
            c = line[i];
            for (int j = 0; j < line.size(); ++j) {
                if (j == i) continue;
                if (line[i] == line[j]) {
                    isRepeated = true;
                    break;
                }
            }
            if (!isRepeated) break;
        }
        cout << c << endl;
    }
    return 0;
}
