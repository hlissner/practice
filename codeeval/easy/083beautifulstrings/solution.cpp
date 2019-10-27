#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int occurrences[26] = {0};

        for (size_t i = 0; i < line.size(); ++i) {
            if (isalpha(line[i])) {
                occurrences[tolower(line[i]) - 'a']++;
            }
        }

        sort(occurrences, occurrences + 26, std::greater<int>());

        int beauty = 0;
        int score = 26;
        for (size_t i = 0; i < 26; ++i) {
            if (occurrences[i] > 0) {
                beauty += score * occurrences[i];
                --score;
            }
        }

        cout << beauty << endl;
    }

    return 0;
}
