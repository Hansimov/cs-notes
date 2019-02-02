// Vector of Vectors to create matrix
//   https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix

#include <iostream>
#include <vector>

using namespace std;

comb(){
    // vector<int> v;
    // v = {1,2,3};
    // for (int i=0; i<v.size(); i++){
    //     cout << v[i];
    // }

    vector<vector<int>> v;
    v.push_back(vector<int> ({0,1}));
    v.push_back(vector<int> ({0,2}));
    v.push_back(vector<int> ({1,2}));
    for (int i=0; i<v.size(); i++){
        for (int j=0; j<v[i].size(); j++){
            cout << v[i][j] << ' ';
        }
        cout << "- ";
    }

    cout << endl;

    // return v;
}

int main(){
    comb();
    return 0;
}