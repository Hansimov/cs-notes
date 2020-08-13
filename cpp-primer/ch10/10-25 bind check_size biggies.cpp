#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(string const& s, string::size_type sz) {
    return s.size() >= sz;
}

void biggies(vector<string> &v, size_t sz) {
    sort(v.begin(), v.end());
    auto uniq_itr = unique(v.begin(), v.end());
    v.erase(uniq_itr,v.end());

    for_each(v.begin(), v.end(), 
        [](string s){
            cout << s << " ";
        });
    cout << endl;
    
    stable_sort(v.begin(), v.end(), 
        [](string const& s1, string const& s2){
            return s1.size() < s2.size();
        });

    auto find_itr = find_if(v.begin(), v.end(), 
        bind(check_size, _1, sz));

    for_each(find_itr, v.end(), 
        [](string s){
           cout << s << " ";
        });
    cout << endl;
}

int main() {
    vector<string> v{"abc","abcddd","abcd","ab","abcd","bcd","aabbcc","abcdd","ab","abcd","bcd","aac","bbccd","abdcd","abdbdbdd","abd","abd","ab","abdbddd","ababababa","ab","babababc"};
    biggies(v, 5);

    return 0;
}