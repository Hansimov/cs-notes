#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// istream& print_data(istream& is) {
istringstream &print_data(istringstream &iss) {
    string buf;
    while (iss >> buf)
        cout << buf << " ";
        // cout << buf << endl;
    iss.clear();
    return iss;

}

int main() {
    // print_data(cin);
    // istream &is = print_data(cin);
    // cout << is.rdstate() << endl;

    istringstream iss("hello\nworld, this\nis a test string.");
    print_data(iss);

    return 0;
}