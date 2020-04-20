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

    // using int_arr = int[4];
    typedef int int_arr[4];
    for (int_arr *p = arr; p!=end(arr); ++p) {
        for (int *q = *p; q!=end(*p); ++q)
            cout << *q << " ";
        cout << endl;
    }


    return 0;
}