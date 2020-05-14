#include "7-53 debug.h"

using namespace std;

int main() {
    constexpr Debug io_sub(false, true, false);

    if (io_sub.any())
        cerr << "Error" << endl;

    Debug hw_sub(true);
    if (hw_sub.all())
        cerr << "Error 2" << endl;
    hw_sub.set_hw(false);
    if (hw_sub.all())
        cerr << "Error 3" << endl;

    Debug other_sub(false);
    if (other_sub.any())
        cerr << "Error 4" << endl;
    other_sub.set_other(true);
    if (other_sub.any())
        cerr << "Error 5" << endl;


    
    return 0;
}