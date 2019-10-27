#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        int arrows = 0;
        int strlen = line.size();
        for (int i = 0; i < strlen; ++i) {
            if (line[i] == '<' && i+5 <= strlen && line.substr(i, 5) == "<--<<") {
                ++arrows;
            }
            if (line[i] == '>' && i+5 <= strlen && line.substr(i, 5) == ">>-->") {
                ++arrows;
            }
        }
        cout << arrows << endl;
    }

    return 0;
}
