#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> vi = {1,2,3,4,5,6};
    cout << accumulate(vi.begin(), vi.end(), 0) << endl;
    vector<double> vd = {1.1, 2.2, 3.3};
    cout << accumulate(vd.begin(), vd.end(), 0) << endl;
    cout << accumulate(vd.begin(), vd.end(), 0.0) << endl;

    return 0;
}