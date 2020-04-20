#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {0,1,2,3,4,5};
    vector<int> vec(begin(arr),end(arr));
    for (auto ele:vec)
        cout << ele <<" ";
    cout << endl;
    cout << vec.size() << endl;

    vector<int> vec2(arr+1,arr+4);
    for (auto ele:vec2)
        cout << ele <<" ";
    cout << endl;
    cout << vec2.size() << endl;

    return 0;
}