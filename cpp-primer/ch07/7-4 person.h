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