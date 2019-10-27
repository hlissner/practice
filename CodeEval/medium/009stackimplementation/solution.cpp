#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        deque<int> nums;

        istringstream ss(line);
        int n;
        while (ss >> n) { nums.push_back(n); }

        for (int i = 0; nums.size() > 0; ++i) {
            if ((i&1) == 0) cout << nums.back() << ' ';
            nums.pop_back();
        }
        cout << endl;
    }
    return 0;
}
