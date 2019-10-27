#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        auto it = line.begin();
        while (*it != ':') { ++it; }

        string lhs(line.begin(), it-1);
        string rhs(it+2, line.end());

        istringstream lhss(lhs);
        vector<int> num;
        int i;
        while (lhss >> i) {
            num.push_back(i);
        }

        istringstream rhss(rhs);
        char sep;
        int x, y;
        while (rhss >> x >> sep >> y) {
            std::swap(num[x], num[y]);
            if (rhss.peek() == ',') rhss.ignore();
        }

        // Display results
        for (int i = 0; i < (int) num.size(); ++i) {
            cout << num[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
