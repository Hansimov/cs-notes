#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

int main() {
    forward_list<int> fli = {1,2,3,4,5};

    auto curr = fli.begin();
    auto prev = fli.before_begin();
    while (curr != fli.end()) {
        if (*curr%2==1) {
            curr = fli.insert_after(curr,*curr);
            prev = curr;
            ++curr;
        } else {
            curr = fli.erase_after(prev);
        }
    }

    for (const auto &i: fli) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}