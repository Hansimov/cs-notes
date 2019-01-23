#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class vec {

public:
    vector<int> v{1,2,3};

public:
    void print(){
        for (int i=0; i<v.size(); i++){
            cout << v[i];
        }
        cout << endl;
    }

    void reverse(){
        std::reverse(v.begin(), v.end());
    }

    vector<char> toChar(){
        vector<char> w(v.size());
        for (int i=0; i<v.size(); i++){
            w[i] = '0' + v[i];
        }
        return w;
    }
};

int main(){
    vec u;
    u.print();
    u.reverse();
    u.print();
    vector<char> w;
    w = u.toChar();

    return 0;
}
