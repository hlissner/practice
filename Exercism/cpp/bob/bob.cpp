#include "bob.h"

// Solution
string bob::hey(const string statement) {
    // Avoid side-effects by working on a copy
    string input(statement);

    // trim right side of the input. No need to care about leading whitespace;
    // it doesn't affect the predicate functions.
    if (input.size() > 0) {
        if (input.size() > 1 && input.back() == ' ')
            input.erase(input.find_last_not_of(' ') + 1);
    }

    if (bob::is_addressing(&input)) {
        return "Fine. Be that way!";
    } else if (bob::is_shouting(&input)) {
        return "Whoa, chill out!";
    } else if (bob::is_questioning(&input)) {
        return "Sure.";
    }

    return "Whatever.";
}

// Helpers
bool bob::is_addressing(const string * const input) {
    return input->size() == 0;
}

bool bob::is_questioning(const string * const input) {
    return input->back() == '?';
}

bool bob::is_shouting(const string * const input) {
    bool hasUpper = false;
    size_t len = input->size();
    for (int i = 0; i < len; ++i) {
        const char c = (*input)[i];
        if (!isalpha(c)) continue;
        // The speaker is shouting if all alphabetical characters are uppercase.
        if (isupper(c))
            hasUpper = true;
        // Even one lower-case character indicates the speaker isn't shouting
        if (c >= 'a' && c <= 'z')
            return false;
    }
    return hasUpper;
}
