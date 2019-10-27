#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        istringstream ss(line);
        deque<char> chars;

        char c;
        while (ss >> c) {
            if (c >= '0' && c <= '9') {
                ss.unget();
                break;
            }

            chars.push_back(c);
        }

        int n;
        ss >> n;

        int i = (chars.size() - 1) - (n - 1);
        cout << (i < 0 ? ' ' : chars[i]) << endl;
    }
    return 0;
}
