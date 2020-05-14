#include "7-32 screen window_mgr.h"

using namespace std;

int main() {
    Screen myScreen(3,3,'X');
    myScreen.display(cout);
    cout << "\n";
    myScreen.move(2,1).set('#').display(cout);
    cout << "\n";
    myScreen.set(1,2,'*').display(cout);
    cout << "\n";

    const Screen myScreen2(3,3,'Y');
    myScreen2.display(cout);
    cout << "\n";

    Screen myScreen3(3,3,'Z');
    myScreen3.display(cout).set(2,2,'%');
    cout << "\n";
    myScreen3.display(cout);
    cout << "\n";

    return 0;
}