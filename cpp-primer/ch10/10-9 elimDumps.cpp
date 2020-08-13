/*
* CppPrimer/ex10_09.cpp at master · pezy/CppPrimer 
    * https://github.com/pezy/CppPrimer/blob/master/ch10/ex10_09.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename Seq> auto println(Seq const& seq) -> ostream& {
    for (auto const & ele : seq)
        cout << ele << " ";
    return cout << endl;
}

void elimDups(vector<int> &v) {
    sort(v.begin(), v.end());
    auto itr = unique(v.begin(), v.end());
    v.erase(itr, v.end());
}

int main() {
    vector<int> v{1,2,3,5,4,5,6,5,4,3,1,7};
    elimDups(v);
    println(v);
    
    return 0;
}