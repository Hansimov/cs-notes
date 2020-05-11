#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main() {
    int a, b;
    string cmd;
    while (cin >> a >> b) {
        try {
            cout << static_cast<float>(a)/b << endl;
            if (b==0) {
                throw runtime_error("divisor cannot be 0!\n");
            }
        } catch (runtime_error err) {
            cout << err.what();
            cout << "type new int? (y/n)\n";
            cin >> cmd;
            if (cmd=="n" || cmd=="N") {
                break;
            }
        }

    }


    return 0;
}