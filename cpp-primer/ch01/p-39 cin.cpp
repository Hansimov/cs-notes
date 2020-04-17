#include <iostream>

int main() {
    int sum = 0, val = 0;
    while (std::cin >> val) {
        sum += val;
    }
    std::cout << "Sum is " << sum << std::endl;
    return 0;
}