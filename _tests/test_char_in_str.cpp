#include <iostream>
#include <string>

using namespace std;

int main () {
    string s = "hello";
    char c = 'o';
    if (s.find(c) == string::npos)
        cout << "Not Found" << endl;
    else
        cout << s.find(c) << endl;
  return 0;
}