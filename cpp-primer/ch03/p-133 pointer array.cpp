#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    constexpr size_t sz = 5;
    int arr[sz] = {1,2,3,4,5};

    int *b = arr, *e = arr+sz;
    while (b < e) {
        cout << *b <<" ";
        ++b;
    }
    cout << endl;
    return 0;
}