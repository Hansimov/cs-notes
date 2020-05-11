#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using iter = vector<int>::iterator;

void print(iter beg, iter end) {
    if (beg != end) {
        cout << *beg << " ";
        print(next(beg),end);
    }
}

int main() {
    vector<int> v = {1,2,3,4,5};
    print(v.begin(), v.end());

    return 0;
}