#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        vector<int> tokens;
        int cols = 0;
        int rows = 0;
        string x;
        for (int i = 0; ss >> x; ++i) {
            if (x == "|") {
                if (cols == 0) cols = i;
                ++rows;
                continue;
            }
            tokens.push_back(strtol(x.c_str(), NULL, 10));
        }

        for (int i = 0; i < cols; ++i) {
            int m = tokens[i];
            for (int j = 1; j <= rows; ++j) {
                m = max(m, tokens[i+(cols*j)]);
            }
            cout << m << (i == cols-1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
