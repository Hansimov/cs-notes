#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const char ca[] = {'h','e','l','l','o'};
    // const char ca[] = {'h','e','l','l','o','\0'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << ' ';
        ++cp;
    }
    cout << endl;
    return 0;
}