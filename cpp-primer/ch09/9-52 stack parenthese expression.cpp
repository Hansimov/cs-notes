#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    stack<char> stk;
    string s = "This is ((((test) val )) do )you) know (about ) it ? (()))(";

    size_t ptr = 0;
    for (auto &c: s) {
        stk.push(c);
        if (c=='(')
            ++ptr;
        if (ptr && c==')') {
            while (stk.top()!='(')
                stk.pop();
            stk.pop();
            stk.push('*');
            --ptr;
        }
    }

    string output;
    while (!stk.empty()) {
        output.insert(output.begin(), stk.top());
        stk.pop();
    }
    cout << output << endl;

    return 0;
}