#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

int sum_all(const initializer_list<int> &lst) {
    int sum=0;
    for (const int &ele: lst)
        sum += ele;
    return sum;
}

int main() {
    
    cout << sum_all({1,2,3,4,5}) << endl;

    return 0;
}