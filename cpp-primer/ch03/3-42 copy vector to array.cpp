#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {0,1,2,3,4,5,6};
    int arr[vec.size()];

    int *p = arr;
    for (auto ele : vec) {
        *p = ele;
        ++p;
    }

    for (auto num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}