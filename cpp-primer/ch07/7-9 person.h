#include <iostream>
#include <string>

class Person {
    string name;
    string addr;
public:
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