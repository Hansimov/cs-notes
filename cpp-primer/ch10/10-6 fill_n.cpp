#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{1,2,3,4,5,6};
    fill_n(v.begin(), v.size(), 0);
    for (auto &ele : v) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}