/*
    0123
    4567
    89AB
    CDEF
                                     
                  0123 4567 89AB CDEF   HEX
                  ---- ---- ---- ----   ++++
    0: 012348C  > 1111 1000 1000 1000   F888
    1: 012359D  > 1111 0100 0100 0100   F444
    2: 01236AE  > 1111 0010 0010 0010   F222
    3: 01237BF  > 1111 0001 0001 0001   F111
    4: 045678C  > 1000 1111 1000 1000   8F88
    5: 145679D  > 0100 1111 0100 0100   4F44
    6: 24567AE  > 0010 1111 0010 0010   2F22
    7: 34567BF  > 0001 1111 0001 0001   1F11
    8: 0489ABC  > 1000 1000 1111 1000   88F8
    9: 1589ABD  > 0100 0100 1111 0100   44F4
    A: 2689ABE  > 0010 0010 1111 0010   22F2
    B: 3789ABF  > 0001 0001 1111 0001   11F1
    C: 048CDEF  > 1000 1000 1000 1111   888F
    D: 159CDEF  > 0100 0100 0100 1111   444F
    E: 26ACEDF  > 0010 0010 0010 1111   222F
    F: 37BCDEF  > 0001 0001 0001 1111   111F
*/

#include <iostream>
// #include <stdio.h>
// #include <cstdio>
#include <string>
// #include <cstring>
// #include <stdlib.h>
// #include <cstdlib>
#include <bitset>
// #include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

long m [16] = {
    0xF888,0xF444,0xF222,0xF111,
    0x8F88,0x4F44,0x2F22,0x1F11,
    0x88F8,0x44F4,0x22F2,0x11F1,
    0x888F,0x444F,0x222F,0x111F,
};

string parseInput(string sin){
    string s;
    for (int i=0; i<sin.size(); i++){
        if (sin[i]!='+' && sin[i]!='-'){
            continue;
        } else {
            // +/w/1: closed == white
            // -/b/0: open == black
            s += (sin[i]=='-' ? "0" : "1");
        }
    }
    return s;
}

long str2long(string s, int base=2){
    long n = strtol(s.c_str(), NULL, base);

    // cout << s << endl;
    // cout << n << endl;
    // cout << hex << n << endl;
    // cout << bitset<16> (n) << endl;

    return n;
}

vector<int> array;
vector<int> state;

long target;
long open   = 0x0000;

int check(long init){
    // for (int i=0; i<state.size(); i++){
    //     cout << state[i] << ' ';
    // }
    // cout << endl;

    long result = init;
    int step;
    if (result == target) {
        step = 0;
    }
    else {
        for (int i=0; i<state.size(); i++){
            result ^= m[state[i]];
        }
        if (result == target) {
            step = state.size();
            // for (int i=0; i<state.size(); i++){
            //     cout << state[i] << ' ';
            // }
        } else {
            step = -1;
        }
    }
    // if (step != -1){
    //     cout << '['<< state.size() << ']' << endl;
    // }
    return step;
}

int search(int offset, int k, long init){
    int step, step_b, step_w;
    if ( k == 0 ) {
        step = check(init);
    }
    else {
        for (int i=offset; i<=array.size()-k; i++){
            state.push_back(array[i]);
            step = search(i+1, k-1, init);
            if (step != -1){
                break;
            }
            state.pop_back();
        }
    }
    return step;
}

int main(){
    // string sin = "-+--\n----\n----\n-+--";
    string sin; char c;
    while(cin >> c){sin += c;}

    string s = parseInput(sin);
    target = str2long(s);
    // cout << bitset<16> (target) << endl;

    int n = s.size();
    int step;
    for (int i=0; i<n; i++){
        array.push_back(i);
    }
    for (int k=0; k<=n; k++){
        step = search(0, k, open);
        if (step != -1){
            // cout << '<' << state.size() << '>' << endl;
            break;
        }
    }

    cout << step << endl;

    int row, col;
    for (int i=0; i<state.size(); i++){
        row = (state[i])/4+1;
        col = (state[i])%4+1;
        cout << row << ' ' << col << endl;
    }

    return 0;
}