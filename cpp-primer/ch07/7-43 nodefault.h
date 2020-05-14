#include <string>

struct NoDefault {
    NoDefault(int) {}
};

struct C {
    NoDefault nd;
    C() : nd(0) {}
};