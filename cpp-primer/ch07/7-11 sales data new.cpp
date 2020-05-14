#include "7-11 sales_data.h"

using namespace std;

int main() {
    Sales_data sd1;
    print(cout, sd1) << endl;

    Sales_data sd2("isbn-22222");
    print(cout, sd2) << endl;

    Sales_data sd3("isbn-33333",3, 30.0);
    print(cout, sd3) << endl;

    Sales_data sd4(cin);
    print(cout, sd4) << endl;

    return 0;
}