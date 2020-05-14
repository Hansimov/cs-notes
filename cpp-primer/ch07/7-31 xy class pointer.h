struct Y;

struct X {
    Y *yp;
};

struct Y {
    X x;
};