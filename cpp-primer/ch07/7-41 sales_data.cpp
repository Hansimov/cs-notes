#include "7-41 sales_data.h"

using namespace std;
int main() {

    Sales_data sd3("isbn-333",3,3.0);
    Sales_data sd1;
    Sales_data sd2("isbn-22");
    Sales_data sd4(cin);

    print(cout,sd1); cout << endl;
    print(cout,sd2); cout << endl;
    print(cout,sd3); cout << endl;
    print(cout,sd4); cout << endl;

    return 0;
}