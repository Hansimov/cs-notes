#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> li{1,2,3,4};
    vector<double> vd(li.begin(), li.end());

    for (auto &it: vd) {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}