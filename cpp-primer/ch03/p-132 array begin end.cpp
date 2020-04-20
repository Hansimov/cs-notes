#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {0,1,2,3,4,-3,6,7,8,9};
    int *pbeg = begin(arr);
    int *pend = end(arr);
    while (pbeg!=pend && *pbeg>=0)
        ++pbeg;
    cout << (*pbeg) << endl;;

    return 0;
}