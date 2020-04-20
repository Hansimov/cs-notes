#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    while (getline(cin,line))
        cout << line.size() << endl;

    return 0;
}