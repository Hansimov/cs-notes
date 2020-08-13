#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a = 1;
    auto f = [a]() mutable {return ++a;};
    cout << f() << endl;
    return 0;
}