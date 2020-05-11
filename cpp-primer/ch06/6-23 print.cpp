#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(const int p) {
    cout << p << endl;
}


void print(const int *p) {
    if (p)
        cout << *p << endl;
}

void print(const char *cp) {
    if (cp)
        while (*cp)
            cout << *cp++;
    cout << endl;
}

void print(const int *beg, const int *end) {
    while (beg != end)
        cout << *beg++ << " ";
    cout << endl;
}

void print(const int a[], size_t sz) {
    for (size_t i=0; i<sz; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void print(int (&a)[2]) {
    for (auto ele: a)
        cout << ele << " ";
    cout << endl;
}

int main() {
    int i = 1;
    int j[2] = {2,3};
    char chrs[6] = "hello";

    print(i);
    print(&i);
    print(j);
    print(begin(j),end(j));
    print(j, end(j)-begin(j));
    print(chrs);

    print(const_cast<const int(&)[2]>(j));

    return 0;
}