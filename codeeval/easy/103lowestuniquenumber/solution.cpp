#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        deque<int> num;

        int i;
        istringstream ss(line);
        while (ss >> i) { num.push_back(i); }

        int lowest = 0, winner = 0;
        for (i = 0; i < num.size(); ++i) {
            bool unique = true;
            for (int j = 0; j < num.size(); ++j) {
                if (j == i) continue;
                if (num[j] == num[i]) {
                    unique = false;
                    break;
                }
            }
            if (unique && (lowest == 0 || lowest > num[i])) {
                lowest = num[i];
                winner = i+1;
            }
        }
        cout << winner << endl;
    }
    return 0;
}
