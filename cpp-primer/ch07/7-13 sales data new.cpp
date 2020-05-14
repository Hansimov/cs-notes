#include "7-12 data_sales.h"

int main() {
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        istream& is = cin;
        while (is) {
            Sales_data trans(is);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}