#include <iostream>
#include <string>

struct Person {
    Person() = default;
    Person(const string n, const string a)
        : name(n), addr(a) {}
    Person(const string n)
        : name(n) {}
    Person(istream &is) {
        read(is, *this);
    }

    string name;
    string addr;

    const string & get_name() const {
        return name;
    };
    const string & get_addr() const {
        return addr;
    }
};

istream &read(istream &is, Person &rhs) {
    is >> rhs.name >> rhs.addr;
    if (!is)
        rhs = Person();
    return is;
}

ostream &print(ostream &os, const Person &rhs) {
    os << rhs.name << " " << rhs.addr;
    return os;
}