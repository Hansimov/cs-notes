#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int &get(int *arr, int idx) {
    return arr[idx];
}

int main() {
    int ia[10];
    for (int i=0; i<10; ++i) {
        get(ia,i) = i;
    }

    for (int i=0; i<10; ++i) {
        cout << ia[i] << " ";
    }
    cout << endl;

    return 0;
}