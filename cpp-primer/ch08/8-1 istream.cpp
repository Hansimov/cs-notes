#include <iostream>
#include <string>

using namespace std;

istream& print_data(istream& is) {
    string buf;
    while (is >> buf)
        cout << buf << endl;
    is.clear();
    return is;

}

int main() {
    // print_data(cin);
    istream &is = print_data(cin);
    cout << is.rdstate() << endl;
    
    return 0;
}