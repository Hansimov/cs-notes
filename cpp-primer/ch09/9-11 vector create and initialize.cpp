#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,2);
    vector<int> v4{1,2,3,4};
    vector<int> v5(v4);
    vector<int> v6(v4.begin(), v4.end());

    return 0;
}