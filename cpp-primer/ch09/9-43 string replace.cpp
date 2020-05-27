#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void func(string &s, const string &oldVal, const string &newVal) {
    string tmp;
    for (auto itr = s.begin(); distance(itr,s.end())>=oldVal.size(); ) {
        tmp.assign(itr,itr+oldVal.size());
        if (tmp==oldVal) {
            s.erase(itr, itr+oldVal.size());
            itr = s.insert(itr,newVal.begin(),newVal.end()); // do not forget to reassign itr since if newVal.size() != oldVal.size(), there will be out_of_range error
            itr += oldVal.size();
        } else {
            ++itr;
        }
    }
}

int main() {
    string s1 = "hello hell hel holo heoolle ollhelo";
    func(s1,"hel","xxxx");
    cout << s1 << endl;

    return 0;
}