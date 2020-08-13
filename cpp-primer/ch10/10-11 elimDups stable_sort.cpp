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

void elimDups(vector<string> &v) {
    sort(v.begin(), v.end());
    auto itr = unique(v.begin(), v.end());
    v.erase(itr, v.end());
}

bool isShorter(string s1, string s2) {
    return s1.size() < s2.size();
}

int main() {
    vector<string> v{"ab","abcd","bcd","aabbcc","abcdd","ab","abcd","bcd","aac","bbccd"};
    elimDups(v);
    println(v);
    
    stable_sort(v.begin(), v.end(), isShorter);
    println(v);
    return 0;
}