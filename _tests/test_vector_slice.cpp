// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> x = {1,2,3,4,5,6};
    vector<int> a;
    a = vector<int>(x.begin(),x.begin());
    for (int i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    // a.erase(a.begin());
    // for (int i=0; i<a.size(); i++) {
    //     cout << a[i] << " ";
    // }
}