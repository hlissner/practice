#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::reverse(input.begin(), input.end());
    std::cout << input << std::endl;

    return 0;
}
