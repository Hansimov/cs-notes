#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void func(string &s, const string &oldVal, const string &newVal) {
    string tmp;

    for (int i=0; i<s.size()-oldVal.size(); ) {
        if (s.substr(i,oldVal.size()) == oldVal) {
            s.replace(i,oldVal.size(),newVal);
            i+=newVal.size()+1;
        } else {
            ++i;
        }
    }

}

int main() {
    string s1 = "hello hell hel holo heoolle ollhelo";
    func(s1,"hel","xxxx");
    cout << s1 << endl;

    return 0;
}