#include "7-1 sales_data.h"

int main() {
    Sales_data total;

    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.AddData(trans);
            } else {
                total.Print();
                total = trans;
            }
        }
        total.Print();
    } else {
        cerr << "No data" << endl;
        return -1;
    }

    return 0;
}