#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    friend istream &read(istream &is, Sales_data &rhs);
    friend ostream &print(ostream &os, const Sales_data &rhs);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

    Sales_data(const string&s, unsigned u, double p)
        : bookNo(s), units_sold(u), revenue(u*p) {
            cout << "3 para" << endl;
        }
    Sales_data(): Sales_data("", 0, 0) {
        cout << "0 para" << endl;
    }
    Sales_data(const string&s): Sales_data(s,0,0) {
        cout << "string para" << endl;
    }

    Sales_data(istream &is): Sales_data() {
        cout << "istream para" << endl;
        read(is, *this);
    }

    Sales_data & combine(const Sales_data &);
    string isbn() const;

    inline double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const {
    return units_sold ? float(revenue)/units_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

string Sales_data::isbn() const {
    return bookNo;
}

// add
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// read
istream &read(istream &is, Sales_data &rhs) {
    double price = 0.0;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    rhs.revenue = price * rhs.units_sold;
    return is;
}

// print
ostream &print(ostream &os, const Sales_data &rhs) {
    os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue;
    return os;
}