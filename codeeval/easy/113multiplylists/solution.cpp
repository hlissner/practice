#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        string::size_type n = line.find('|');
        string lhs = line.substr(0, n-1);
        string rhs = line.substr(n+2, line.size());

        istringstream lhss(lhs);
        istringstream rhss(rhs);
        int x, y;
        while (lhss >> x && rhss >> y) {
            cout << (x * y) << ' ';
        }
        cout << endl;
    }

    return 0;
}
