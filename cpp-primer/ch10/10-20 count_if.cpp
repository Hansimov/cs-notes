#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> v{"abc","abcddd","abcd","ab","abcd","bcd","aabbcc","abcdd","ab","abcd","bcd","aac","bbccd","abdcd","abdbdbdd","abd","abd","ab","abdbddd","ababababa","ab","babababc"};
    cout << count_if(v.begin(), v.end(), 
        [](string const& s){
            return s.size() >= 5;
        }) << endl;

    return 0;
}