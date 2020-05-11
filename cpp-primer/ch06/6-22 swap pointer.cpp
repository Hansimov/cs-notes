#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap_pointer(const int* (&a), const int* (&b)) {
    const int *tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int an = 2, bn = 3;
    const int *ap = &an, *bp = &bn;
    cout << *ap << " " << *bp << endl;
    swap_pointer(ap,bp);
    cout << *ap << " " << *bp << endl;

    return 0;
}