#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto add = [](int a, int b) {return a+b;};
    cout << add(1,3) << endl;

    return 0;
}