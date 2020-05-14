typedef string Type;
Type initVal();     // use `string`
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);  // use `double`
    Type initVal();     // use `double`
private:
    int val;
};

// Type Exercise::setVal(Type parm) {  // return is `string`, parm is `double`
Exercise::Type Exercise::setVal(Type parm) {  // return is `double`, parm is `double`
    // val = parm + initVal();
    val = parm + initVal(); // Need to be defined
    return val;
}