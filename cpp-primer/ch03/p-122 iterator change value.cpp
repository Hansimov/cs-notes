#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s("hello world");
    // if (s.begin() != s.end()) {
    //     auto itr = s.begin();
    //     *itr = toupper(*itr);
    // }
    for (auto itr=s.begin(); itr!=s.end() && !isspace(*itr); ++itr)
        *itr = toupper(*itr);
    cout << s << endl;
    return 0;
}