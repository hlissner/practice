#include <iostream>
#include <fstream>

using namespace std;

const string slang[] = {
    ", yeah!",
    ", this is crazy, I tell ya.",
    ", can U believe this?",
    ", eh?",
    ", aw yea.",
    ", yo.",
    "? No way!",
    ". Awesome!"
};

int main(int argc, char *argv[]) {
    ifstream file(argv[1]);

    short slang_id = 0;
    bool other = false;
    string line;
    while (getline(file, line)) {
        auto it = line.begin();
        auto end = line.end();
        while (it != end) {
            char c = *it;
            if (c == '.' || c == '?' || c == '!') {
                if (other) {
                    cout << slang[slang_id++];
                    if (slang_id > 7) {
                        slang_id = 0;
                    }
                } else {
                    cout << c;
                }
                other = !other;
            } else {
                cout << c;
            }
            ++it;
        }
        cout << endl;
    }
    return 0;
}
