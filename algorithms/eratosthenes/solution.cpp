#include <iostream>

void eratosthenes(bool *nums, unsigned int max) {
    nums[0] = nums[1] = 1;
    for (unsigned int i = 2; i < max; ++i) {
        if (!nums[i]) {
            std::cout << i << std::endl;
            for (auto j = i*i; j < max; j+=i) {
                nums[j] = 1;
            }
        }
    }
}

int main() {
    const unsigned int max = 10e6;
    bool *nums = new bool[max];
    eratosthenes(nums, max);
    delete[] nums;
    return 0;
}
