#include "sum_of_multiples.h"

int sum_of_multiples(const unsigned int* nums, const size_t len, const unsigned max) {
    if (nums == NULL) {
        return 0;
    }

    unsigned int sum = 0;
    for (unsigned int n = nums[0]; n < max; ++n) {  // assume nums is sorted
        for (size_t i = 0; i < len; ++i) {
            if (nums[i] && !(n % nums[i])) {
                sum += n;
                break;
            }
        }
    }
    return sum;
}
