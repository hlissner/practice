#include <iostream>
#include <assert.h>

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

typedef unsigned int uint;

const int MAX_TRIES = 200;
const int MAX_DIGITS = 11;

struct Range {
    uint start;
    uint end;

    Range(const char *arg, uint len) {
        bool has_hyphen = false;
        char lhs[MAX_DIGITS] = {0};
        char rhs[MAX_DIGITS] = {0};
        char *ptr = lhs;
        // prevent overflow
        if (len > MAX_DIGITS) len = MAX_DIGITS;
        for (uint i = 0; i < len; ++i) {
            if (arg[i] == '-') {
                has_hyphen = true;
                ptr = rhs;
                len = i + MAX_DIGITS;  // reset len for rhs
            } else if (isdigit(arg[i])) {
                *ptr = arg[i];
                ++ptr;
            }
        }

        if (has_hyphen) {
            assert(isdigit(*lhs) && isdigit(*rhs));
            start = atoi(lhs);
            end = atoi(rhs);
        } else {
            start = atoi(arg);
            end = atoi(arg);
        }
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
            Range range(argv[i], (sizeof(argv[i])/sizeof(*argv[i])));

            if (range.start > range.end) {
                cout << "Can't process range: " << range.start << "-" << range.end << endl;
            } else {
                for (uint j = range.start; j <= range.end; ++j) {
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
