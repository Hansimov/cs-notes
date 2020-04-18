#include <iostream>
#include <typeinfo>

int main() {
    int a=3, b=4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

    // std::cout << typeid(a).name() << " " << typeid(b).name() << " " << typeid(c).name() << " " << typeid(d).name() << std::endl;
    // i i i i 

    // Notes: typeid(x).name() is not suitable for decltype()
    // More details:
    //   Is it possible to print a variable's type in standard C++? - Stack Overflow 
    //     https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c

    std::cout << a << " " << b << " " << c << " " << d << std::endl;
    // a: int, b: int, c: int, d:int &
    // 4 4 4 4

    return 0;
}
