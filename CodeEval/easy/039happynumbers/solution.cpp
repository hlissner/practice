#include <iostream>
#include <fstream>

const int MAX_TRIES = 100;

int happy_proc(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool is_happy(int n) {
    for (int i = 0; n != 1 && i < MAX_TRIES; ++i)
        n = happy_proc(n);
    return n == 1;
}

int main(int argc, char *argv[]) {
    std::ifstream infile(argv[1]);
    int i;
    while (infile >> i) {
        std::cout << (is_happy(i) ? 1 : 0) << std::endl;
    }
    return 0;
}
