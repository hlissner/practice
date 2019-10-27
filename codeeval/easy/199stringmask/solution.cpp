#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string str;
    while (getline(infile, str, ' ')) {
        string mask;
        getline(infile, mask, '\n');

        for (int i = 0; i < str.size(); ++i) {
            if (mask[i] == '1')
                str[i] = toupper(str[i]);
        }
        cout << str << endl;
    }

    return 0;
}
