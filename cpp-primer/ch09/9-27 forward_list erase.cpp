#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

int main() {
    forward_list<int> fli = {0,1,2,3,4,5,6,7,8,9,10};

    auto prev = fli.before_begin();
    auto curr = fli.begin();

    while (curr!=fli.end()) {
        if (*curr%2==1)
            curr = fli.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }

    for (const auto &i: fli)
        cout << i << " ";
    cout << endl;

    return 0;
}