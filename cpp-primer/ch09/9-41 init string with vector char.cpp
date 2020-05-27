#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<char> vc = {'h','e','l','l','o'};
    string s(vc.begin(),vc.end());
    cout << s << endl;

    return 0;
}