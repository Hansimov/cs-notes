#include "_utils.h"
#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> & a) {
    for (int i=1; i<a.size(); ++i) {
        int val = a[i];
        int j = i;
        while (--j >= 0) {
            if (a[j] > val)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = val;
    }
}

int main() {
    vector<int> a = {6,5,2,9,1,8,7,3,4};
    disp(a);
    insertion_sort(a);
    disp(a);
    return 0;
}