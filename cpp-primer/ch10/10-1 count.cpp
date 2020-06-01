#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {1,2,3,3,4,4,5,6,7,33,33,33,3};
    cout << count(begin(arr), end(arr), 3) << endl;
    list<string> ls = {"a","a","b","c","c","c","d","cc","c"};
    cout << count(begin(ls), end(ls), "c") << endl;


    return 0;
}