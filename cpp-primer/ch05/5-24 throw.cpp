#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // without throw:  a=1 b=0, cout "inf"
    if (b==0) {
        throw runtime_error("divisor cannot be 0!");
    }
    cout << static_cast<float>(a)/b << endl;
    // terminate called after throwing an instance of 'std::runtime_error' what():  divisor cannot be 0!

    return 0;
}