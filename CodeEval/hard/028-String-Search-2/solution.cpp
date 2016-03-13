#include <iostream>
#include <fstream>

using namespace std;

bool issubstr(const string* src, const string* sub) {
    auto xpos = src->begin(), xend = src->end();
    auto ypos = sub->begin(), yend = sub->end();

    if (*ypos == '*') ++ypos;
    if (*(yend-1) == '*') --yend;

    while (xpos != xend && ypos != yend) {
        if (*xpos == *ypos) {
            bool found = true;
            for (auto x = xpos+1, y = ypos+1; x != xend && y != yend; ++x, ++y) {
                if (*y == '\\' && *(y+1) == '*') ++y;
                if (*y == '*' && *(y-1) != '\\') {
                    ++y;
                    char next = *y;
                    while (x != xend && *x != next) ++x;
                    if (*x != next) {
                        found = false;
                        break;
                    }
                }
                if (*y != *x) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }

        ++xpos;
    }
    return false;
}

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string line;
    while (getline(infile, line)) {
        // I could use std::find, but it doesn't seem to work on CodeEval?
        string::iterator delim = line.begin();
        while (*delim != ',') ++delim;

        string src = string(line.begin(), delim);
        string sub = string(delim+1, line.end());

        cout << (issubstr(&src, &sub) ? "true" : "false") << endl;
    }

    return 0;
}
