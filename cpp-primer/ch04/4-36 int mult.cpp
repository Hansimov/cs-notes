#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int i = 3;
    double d = 3.3;
    // i*= static_cast<int>(d);
    i*= int(d);
    cout << i << endl;   

    return 0;
}