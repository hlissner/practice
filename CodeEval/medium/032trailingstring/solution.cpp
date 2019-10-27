#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string a;
    while (getline(infile, a, ',')) {
        string b;
        getline(infile, b, '\n');

        bool atEnd = true;
        int i = a.size()-1;
        int j = b.size()-1;
        int iEnd = (i+1) - (j+1);
        if (iEnd < 0) {
            atEnd = false;
        } else {
            while (i >= iEnd && j >= 0) {
                if (a[i] != b[j]) {
                    atEnd = false;
                    break;
                }
                --i; --j;
            }
        }
        cout << (atEnd ? 1 : 0) << endl;
    }
    return 0;
}
