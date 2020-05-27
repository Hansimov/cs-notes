#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
    Date(const string &str="");
    void print();
    unsigned year   = 1970;
    unsigned month  = 1;
    unsigned day    = 1;
private:
    vector<string> month_names{"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    unsigned str_to_month(string str);
};

Date::Date(const string &str) {
    if (str.empty())
        return ;
    string delimeters{" ,/"};
    auto month_day_deli_pos = str.find_first_of(delimeters);
    if (month_day_deli_pos == string::npos)
        throw invalid_argument("Invalid format!");
    month = str_to_month(str.substr(0,month_day_deli_pos));
    auto day_year_deli_pos = str.find_first_of(delimeters,month_day_deli_pos+1);
    day = stoi(str.substr(month_day_deli_pos+1,day_year_deli_pos-month_day_deli_pos-1));
    year = stoi(str.substr(day_year_deli_pos+1));
}

void Date::print() {
    cout << year << "-" << month << "-" << day << "\n";
}

unsigned Date::str_to_month(string str) {
    if (str.empty())
        return 0;
    if (isdigit(str[0]))
        return stoi(str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    // cout << str << endl;
    // auto itr = find(month_names.begin(), month_names.end(), str);
    // if (itr != month_names.end())
    //     return distance(month_names.begin(), itr) + 1;
    // else
    //     return 0;
    for (size_t i=0; i<12; ++i) {
        if (str.find(month_names[i]) != string::npos)
            return i+1;
    }
    return 0;
}

int main() {
    auto dt1 = Date();
    dt1.print();

    auto dt2 = Date("February 2, 2002");
    dt2.print();

    auto dt3 = Date("Mar 3, 2003");
    dt3.print();

    auto dt4 = Date("4/4/2004");
    dt4.print();

    auto dt5 = Date("05/05/2005");
    dt5.print();

    return 0;
}