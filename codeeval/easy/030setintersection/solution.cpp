#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> a, b;
        vector<int> *cur = &a;
        stringstream ss(line);

        // divvy up input into the two arrays
        short i;
        while (ss >> i) {
            cur->push_back(i);

            switch (ss.peek()) {
            case ';': cur = &b;
            case ',': ss.ignore();
            }
        }

        vector<int> result;

        // No need to sort, the input rules say it will always be presorted
        // You can use std::set_intersection, but that would be too easy:
        //
        // #include<algorithm>
        // set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));

        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < b.size(); ++j) {
                if (a[i] == b[j]) {
                    result.push_back(b[j]);
                    break;
                }
            }
        }

        // Print it out
        for (size_t i = 0; i < result.size(); ++i) {
            if (i != 0) cout << ",";
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
