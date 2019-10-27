#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        float n;
        set<float> set;
        while (ss >> n) set.insert(n);
        auto it = set.begin();
        cout << fixed << setprecision(3) << *it;
        for (++it; it != set.end(); ++it)
            cout << setprecision(3) << " " << *it;
        cout << endl;
    }

    return 0;
}
