#include <iostream>
#include <string.h>
#include <stdlib.h>

// How to use:
//   clang++ -o solution solution.cpp
//      (or just `make solution`)
//   ./solution 10 11 12
//       Checks if 10, 11 and 12 are happy numbers
//   ./solution 10-12 15 19-30
//       Checks if 10-12, 15 and 19-30 are happy numbers
//   ./solution
//       Get's first 8 happy numbers

using namespace std;

const int MAX_TRIES = 200;

struct Range {
    long start;
    long end;

    Range(const char *arg) {
        char *end;
        this->start = strtol(arg, &end, 10);
        this->end = strstr(arg, "-") > 0 ? strtol(end+1, &end, 10) : this->start;
    }
};

/**
 * Go through each digit, square them and add them together
 */
int happy_proc(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;  // move to next digit
    }
    return sum;
}

/**
 * Proc the happy formula as many times as it takes for it to become 1.
 * MAX_TRIES serves as an infinite loop guard.
 */
bool is_happy(int n) {
    for (int i = 0; n != 1 && i < MAX_TRIES; ++i)
        n = happy_proc(n);
    return n == 1;
}

////////////////////////////////////////

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            Range range(argv[i]);

            if (range.start > range.end) {
                cout << "Can't process range: " << range.start << "-" << range.end << endl;
            } else {
                for (int j = range.start; j <= range.end; ++j) {
                    cout << j << " " << (is_happy(j) ? "Happy!" : "Unhappy.") << endl;
                }
            }
        }
    } else {
        cout << "Printing first 8 happy numbers" << endl;
        for (int i = 1, happy = 0; happy <= 8; ++i) {
            if (is_happy(i)) {
                cout << i << endl;
                ++happy;
            }
        }
    }

    return 0;
}
