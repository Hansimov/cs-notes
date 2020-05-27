#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

void func(forward_list<string> &fls, string s1, string s2) {
    auto prev = fls.before_begin();
    for (auto itr=fls.begin(); itr!=fls.end(); ++itr) {
        if (*itr==s1) {
            fls.insert_after(itr, s2);
            return ;
        } else {
            prev = itr;
        }
    }
    fls.insert_after(prev, s2);
    return ;
}

int main() {
    forward_list<string> fls = {"apple", "bear", "cat", "dog", "egg", "food"};
    string s1 = "bear", s2 = "goose";
    // string s1 = "food", s2 = "goose";
    // string s1 = "ham", s2 = "goose";
    func(fls,s1,s2);
    for (auto const &s: fls)
        cout << s << " ";
    cout << endl;



    return 0;
}