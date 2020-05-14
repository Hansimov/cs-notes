#include "7-27 screen.h"

using namespace std;

int main() {
    Screen myScreen(5,5,'X');
    myScreen.display(cout);
    cout << "\n";
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.set(3,3,'*').display(cout);

    return 0;
}