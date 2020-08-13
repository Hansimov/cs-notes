#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(string const &s, string::size_type sz) {
    return sz > s.size();
}

int main() {
    vector<int> v{1,2,3,5,6,7};
    string s("hello");

    auto find_itr = find_if(v.begin(), v.end(), bind(check_size, s, _1));
    cout << *find_itr << endl;
    return 0;
}