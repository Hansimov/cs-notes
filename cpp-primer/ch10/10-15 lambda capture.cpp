#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a = 1, b=4;
    auto sum = [a](int b){return a+b;};
    cout << sum(5) << endl;

    return 0;
}