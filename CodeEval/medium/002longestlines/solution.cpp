#include <iostream>
#include <fstream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    list<string> lines;
    string line;
    int n;
    infile >> n;
    while (getline(infile, line)) {
        if (lines.size() == 0) {
            lines.push_back(line);
        } else {
            for (auto it = lines.begin(); it != lines.end(); ++it) {
                if (line.size() > it->size()) {
                    lines.insert(it, line);
                    break;
                }
            }
        }
    }
    int i = 0;
    for (auto& l : lines) {
        if (i == n) break;
        cout << l << endl;
        ++i;
    }
    return 0;
}
