#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<const char *> lcp{"hello", "world", "this", "is", "list"};
    vector<string> vs;

    vs.assign(lcp.begin(), lcp.end());

    for (const auto &s: vs) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}