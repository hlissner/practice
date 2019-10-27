#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    int x, y;
    char delim;
    while (infile >> x >> delim >> y)
        cout << (x - y * (int) (x / y)) << endl;
    return 0;
}
