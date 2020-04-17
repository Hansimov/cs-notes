#include <iostream>

int main() {
    int a=0,b=0;
    std::cout << "Input two integer: ";
    std::cin >> a >> b;
    int min = a<=b? a : b;
    int max = a>=b? a : b;
    for (int i=min; i<=max; i++) {
        std::cout << i << " ";
    }
}