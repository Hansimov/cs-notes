#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1 = {0,1,1,2,3,4,6}; 
    vector<int> v2 = {0,1,1,2}; 
    vector<int> v3 = {0,1,1,2,3,5}; 

    bool is_v_prefix = true;
    // int min_size = min(v1.size(),v2.size());
    // for (int i=0; i<min_size; ++i) {
    //     if (v1[i]!=v2[i]) {
    auto min_size = min(v1.size(),v3.size());
    for (decltype(min_size) i=0; i<min_size; ++i) {
        if (v1[i]!=v3[i]) {
            is_v_prefix = false;
            cout << "Is not prefix!" << endl;
        }
    }
    if (is_v_prefix)
        cout << "Is prefix." << endl;

    return 0;
}