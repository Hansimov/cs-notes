#include <vector>

using namespace std;

class Example {
public:
    // static double rate = 6.5; // error: 'constexpr' needed for in-class initialization of static data member
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    // static vector<double> vec(vecSize); // error: 'vecSize' is not a type | we cannot specify an in-class initializer inside parentheses
    // static vector<double> vec{vecSize}; // error: non-constant in-class initialization invalid for static member 
        // * c++ - Why can't I initialize non-const static member or static array in class? - Stack Overflow 
        // ** https://stackoverflow.com/questions/9656941/why-cant-i-initialize-non-const-static-member-or-static-array-in-class
    static vector<double> vec;
};

constexpr double Example::rate;
// vector<double> Example::vec(Example::vecSize);
// vector<double> Example::vec();
vector<double> Example::vec;

int main() {
    
    
    return 0;
}