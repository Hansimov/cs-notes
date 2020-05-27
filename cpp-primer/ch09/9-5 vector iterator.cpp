#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool find(vector<int>::iterator beg, vector<int>::iterator end, int i) {
    while (beg != end) {
        if (*beg == i)
            return true;
        ++beg;
    }
    // for (auto itr=beg; itr!=end; ++itr) {
    //     if (*itr == i)
    //         return true;
    // }
    return false;
}

int main() {
    vector<int> v = {1,2,3,4,5};
    cout << find(v.begin(), v.end(), 2) << endl;
    cout << find(v.begin(), v.end(), 6) << endl;

    return 0;
}