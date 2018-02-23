#include "all_your_base.h"

void reverse(int8_t digits[], uint16_t length) {
    for (int i = 0, j = length-1; i < j; ++i, --j) {
        int temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
    }
}

int invalid_base(int base) {
    return base <= 1 || base > INT16_MAX;
}

size_t rebase(int8_t digits[], uint16_t input_base, uint16_t output_base, size_t input_length) {
    if (invalid_base(input_base)  ||
        invalid_base(output_base) ||
        (input_length && digits[0] == 0))
        return 0;

    // base N => base 10
    int number = 0;
    int i = 0;
    while (i < (int) input_length) {
        if (digits[i] >= input_base)
            return 0;

        number += digits[i] * pow(input_base, (input_length-1)-i);
        digits[i] = 0;
        ++i;
    }

    // base 10 => base M
    for (i = 0; number > 0; ++i) {
        digits[i] = number % output_base; // filled in reverse
        number = floor(number / output_base);
    }
    reverse(digits, i);
    return i;
}
