#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

size_t count_calls() {
    static size_t cnt = 0;
    return ++cnt;
}

int main() {
    
    for (int i=0; i<10; ++i) {
        cout << count_calls() << endl;
    }

    return 0;
}