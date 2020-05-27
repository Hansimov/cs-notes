#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    list<int> li{1,2,3,4,5,6,7,8,9};
    deque<int> dqo, dqe;

    for (const auto &i: li) {
        if (i%2==0)
            dqe.push_back(i);
        else
            dqo.push_back(i);
    }

    for (const auto &i: dqe)
        cout << i << " ";
    cout << endl;
    for (const auto &i: dqo)
        cout << i << " ";
    cout << endl;

    return 0;
}