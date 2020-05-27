#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // vector<int> v = {1,2,3,4,5};
    vector<int> v = {};
    cout << v.at(0) << endl;    // out_of_range
    cout << v[0] << endl;       // segmentation fault
    cout << v.front() << endl;  // segmentation fault
    cout << *v.begin() << endl; // segmentation fault

    return 0;
}