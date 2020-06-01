#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char s1[10] = "abcde";
    char s2[10] = "abcde";
    cout << equal(begin(s1), end(s1), begin(s2)) << endl;
    vector<char*> s3{s1};
    vector<char*> s4{s2};
    cout << equal(begin(s3), end(s3), begin(s4)) << endl;

    return 0;
}