#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x = 5;
    auto f = [&x]() -> bool {
        if (x==0) return true;
        while (x>0) --x;
        return false;
    };
    cout << f() << endl;
    cout << x << endl;
    cout << f() << endl;
    return 0;
}