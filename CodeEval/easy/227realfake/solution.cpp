#include <iostream>
#include <fstream>

using namespace std;

int main(int, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        int sum = 0, j = 0;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ' ') {
                j = 0;
                continue;
            }
            short n = line[i] - '0';
            sum += (j%2 == 0 ? n * 2 : n);
            ++j;
        }
        cout << (sum % 10 == 0 ? "Real" : "Fake") << endl;;
    }
    return 0;
}
