#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NDEBUG

int main() {
#ifndef NDEBUG
    cout << "not def NDEBUG" << endl;
#endif

    return 0;
}