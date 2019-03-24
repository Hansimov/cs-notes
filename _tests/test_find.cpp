// Check if element found in array c++
//   https://stackoverflow.com/questions/19215027/check-if-element-found-in-array-c

#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

using namespace std;

int main() {

    int ints[] = {0,1,2,3};
    int *p;
    p = find(ints, end(ints), 3);

    if (p != end(ints))
        cout << distance(ints, p) << endl;

    char chars[] = {'0', '1', '2', '3'};
    char *q;
    q = find(chars, end(chars), '2');
    if (q != end(chars))
        cout << distance(chars, q) << endl;
    return 0;
}