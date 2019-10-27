#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        bool selfdesc = false;
        for (size_t i = 0; i < line.size(); ++i) {
            int n = (int) line[i] - '0';
            int count = 0;
            for (size_t j = 0; j < line.size(); ++j) {
                if (line[j] - '0' == (int) i) ++count;
            }

            if (n != count) {
                selfdesc = false;
                break;
            }
            selfdesc = true;
        }
        cout << (selfdesc ? '1' : '0') << endl;
    }

    return 0;
}
