#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vi = {};
    cout << vi.capacity() << endl;
    for (int i=0; i<20; ++i) {
        vi.push_back(i);
        cout << vi.size() << " " << vi.capacity() << endl;
    }

    vi.reserve(100);
    cout << vi.size() << " " << vi.capacity() << endl;
    vi.shrink_to_fit();
    cout << vi.size() << " " << vi.capacity() << endl;

    return 0;
}