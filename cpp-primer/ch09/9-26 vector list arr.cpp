#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> vi;
    list<int> li;
    for (const int &i: ia) {
        vi.push_back(i);
        li.push_back(i);
    }

    for (vector<int>::iterator itr=vi.begin(); itr!=vi.end();) {
        if (*itr%2==1)
            itr = vi.erase(itr);
        else
            ++itr;
    }

    for (const auto &i: vi) {
        cout << i << " ";
    }
    cout << endl;

    for (list<int>::iterator itr=li.begin(); itr!=li.end();) {
        if (*itr%2==0)
            itr = li.erase(itr);
        else
            ++itr;
    }

    for (const auto &i: li) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}