#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int f(int a,int b);

int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int dvd(int a, int b) { return a/b; } // "div" will conflict

int main() {
    vector<decltype(f)*> v{add,sub,mul,dvd};
    for (auto fc: v) {
        cout << fc(4,3) << endl;
    }

    return 0;
}