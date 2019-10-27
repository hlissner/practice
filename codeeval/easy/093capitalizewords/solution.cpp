#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        for (size_t i = 0; i < line.size(); ++i) {
            if (isalpha(line[i]) && (i == 0 || line[i-1] == ' ')) {
                line[i] = toupper(line[i]);
            }
        }
        cout << line << endl;
    }
    return 0;
}
