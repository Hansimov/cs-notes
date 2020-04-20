#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int arr[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

    for (auto p = arr; p!=end(arr); ++p) {
        for (auto q = *p; q!=end(*p); ++q)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}