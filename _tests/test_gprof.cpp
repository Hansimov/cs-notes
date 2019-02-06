#include <stdio.h>

using namespace std;

int main() {
    int c = 0;
    for (int i=0; i<20000; ++i) {
        c += i;
    }
    printf("%d\n", c);

    return 0;
}