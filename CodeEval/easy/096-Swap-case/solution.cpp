#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(int, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        size_t size = line.size();
        for (int i = 0; i < size; ++i) {
            char c = line[i];
            if (isalpha(c)) {
                line[i] = isupper(c) ? tolower(c) : toupper(c);
            }
        }
        cout << line << endl;
    }
    return 0;
}
