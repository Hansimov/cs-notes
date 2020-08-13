#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../ch07/7-26 sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
    return sd1.isbn() < sd2.isbn();
}

int main() {
    Sales_data sd1("abcd"), sd2("bca"), sd3("abb"), sd4("abc"), sd5("aab"), sd6("aaaaa"), sd7("ba"), sd8("ab");
    vector<Sales_data> v{sd1,sd2,sd3,sd4,sd5,sd6,sd7,sd8};
    sort(v.begin(), v.end(), compareIsbn);
    for (const auto & ele : v) {
        cout << ele.isbn() << " ";
    }
    cout << endl;
    return 0;
}