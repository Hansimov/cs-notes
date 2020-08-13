#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool moreThanFiveWords(const string s1) {
    return s1.size() >= 5;
}

int main() {
    vector<string> v{"abc","abcddd","abcd","abdcd","abdbdbdd","abd","abd","ab","abdbddd","ababababa","ab","babababc"};

    vector<string>::iterator bound = stable_partition(v.begin(), v.end(), moreThanFiveWords);

    for (auto & ele : v)
        cout << ele << " ";
    cout << endl;
    for (vector<string>::iterator it = v.begin(); it!=bound; ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}