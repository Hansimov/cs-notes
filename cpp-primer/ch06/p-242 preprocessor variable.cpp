#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << __func__ << endl;
    cout << __LINE__ << endl;
    cout << __FILE__ << endl;
    cout << __DATE__ << " " << __TIME__ << endl;

    return 0;
}