#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

    auto part_itr = partition(v.begin(), v.end(),
        [sz](string const &s){
            return s.size() <= sz;
        });

    auto s_part_itr = stable_partition(v.begin(), v.end(),
        [sz](string const &s){
            return s.size() <= sz;
        });

    for_each(part_itr, v.end(), 
        [](string s){
           cout << s << " ";
        });
    cout << endl;

    for_each(s_part_itr, v.end(), 
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