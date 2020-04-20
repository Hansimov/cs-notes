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

    // // v1: use range for
    // for (const int (&p)[4] : arr) {
    //     for (int q : p)
    //         cout << q << " ";
    //     cout << endl;
    // }

    // // v2: use subscripts
    // for (size_t i=0; i<end(arr)-begin(arr); ++i) {
    //     for (size_t j=0; j<end(arr[0])-begin(arr[0]); ++j)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }

    // // v3: use pointers
    // for (int (*p)[4]=arr; p!=end(arr); ++p) {
    //     for (int *q=*p; q!=end(*p); ++q)
    //         cout << *q << " ";
    //     cout << endl;
    // }

    // // v4: use typedef
    // using int_arr = int[4];
    // for (int_arr &p : arr) {
    // // must use & here to prevent p being convered to pointer
    //     for (int q : p)
    //         cout << q << " ";
    //     cout << endl;
    // }

    // // v5: use auto
    // for (auto &p : arr) {
    //     for (auto q : p)
    //         cout << q << " ";
    //     cout << endl;
    // }




    return 0;
}