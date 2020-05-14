#include <iostream>
#include "7-57 account.h"

using namespace std;

int main() {
    Account acc;
    cout << acc.rate() << endl;
    acc.rate(5.55);
    cout << acc.rate() << endl;
    
    return 0;
}