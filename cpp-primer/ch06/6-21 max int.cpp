#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// int max_num(int a, int *b) {
int max_num(const int a, const int * const b) {
    return a>*b?a:*b;
}

int main() {
    int x = 2;
    int y = 3;
    cout << max_num(x, &y) << endl;
    cout << max_num(5, &y) << endl;

    return 0;
}