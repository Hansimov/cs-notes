#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>::iterator find(vector<int>::iterator beg, vector<int>::iterator end, int i) {
    while (beg != end) {
        if (*beg == i)
            return beg;
        ++beg;
    }
    return end;
}

int main() {
    vector<int> v = {1,2,3,4,5};
    cout << *find(v.begin(), v.end(), 2) << endl;
    cout << *find(v.begin(), v.end(), 9) << endl;

    return 0;
}