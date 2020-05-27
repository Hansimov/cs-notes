#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // vector<string> vs = {"10","200","3000","40000","500000"};
    // int sum = 0;
    // for (const auto &s: vs) {
    //     sum += stoi(s);
    // }
    // vector<string> vs = {"10.1","200.1","3000.1","40000.1","500000.1"};
    // vector<string> vs = {"10.01","200.002","3000.0003","40000.00004"};
    vector<string> vs = {"10.01","200.002"};
    float sum = 0.0;
    for (const auto &s: vs) {
        sum += stof(s);
        // cout << stof(s) << " ";
    }

    cout << sum << endl;

    return 0;
}