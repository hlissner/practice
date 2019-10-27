#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        float up = 0, down = 0;
        int size = line.size();
        for (int i = 0; i < size; ++i) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                ++down;
            } else if (line[i] >= 'A' && line[i] <= 'Z') {
                ++up;
            }
        }

        float downp = (down / size) * 100;
        float upp   = (up / size) * 100;

        cout << setprecision(2) << fixed
             << "lowercase: "  << downp
             << " uppercase: " << upp
             << endl;;
    }
    return 0;
}
