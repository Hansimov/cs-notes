#include <string>
#include <iostream>
#include <type_traits>

using namespace std;

struct Data {
    int ival;
    string s; // `string` is not a literal type
};

int main() {
    cout << is_literal_type<Data>::value << endl;

    return 0;
}