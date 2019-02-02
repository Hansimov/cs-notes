/*
    0123
    4567
    89AB
    CDEF
                                     
                    0123 4567 89AB CDEF  HEX
                    ---- ---- ---- ----  ++++
    0: 0+1+4      > 1100 1000 0000 0000  C800
    1: 0+1+2+5    > 1110 0100 0000 0000  E400
    2: 1+2+3+6    > 0111 0010 0000 0000  7200
    3: 2+3+7      > 0011 0001 0000 0000  3100
    4: 0+4+5+8    > 1000 1100 1000 0000  8C80
    5: 1+4+5+6+9  > 0100 1110 0100 0000  4E40
    6: 2+5+6+7+A  > 0010 0111 0010 0000  2720
    7: 3+6+7+B    > 0001 0011 0001 0000  1310
    8: 4+8+9+C    > 0000 1000 1100 1000  08C8
    9: 5+8+9+A+D  > 0000 0100 1110 0100  04E4
    A: 6+9+A+B+E  > 0000 0010 0111 0010  0272
    B: 7+A+B+F    > 0000 0001 0011 0001  0131
    C: 8+C+D      > 0000 0000 1000 1100  008C
    D: 9+C+D+E    > 0000 0000 0100 1110  004E
    E: A+D+E+F    > 0000 0000 0010 0111  0027
    F: B+E+F      > 0000 0000 0001 0011  0013
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
    0xC800, 0xE400, 0x7200, 0x3100,
    0x8C80, 0x4E40, 0x2720, 0x1310,
    0x08C8, 0x04E4, 0x0272, 0x0131,
    0x008C, 0x004E, 0x0027, 0x0013,
};

string parseInput(string sin){
    string s;
    for (int i=0; i<sin.size(); i++){
        if (sin[i]!='w' && sin[i]!='b'){
            continue;
        } else {
            s += (sin[i]=='b' ? "0" : "1");
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
long white = 0xFFFF;
long black = 0x0000;

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
    // cout << "==== Compiled ====" << endl;
    // string sin = "wwww\nbbbb\nbwbw\nwbwb";
    // string sin = "bwbw\nwwww\nbbwb\nbwwb";
    // string sin = "bwwb\nbbwb\nbwwb\nbwww";
    // string sin = "wwww\nwwww\nwwww\nwwww";
    // string sin = "bbbb\nbbbb\nbbbb\nbbbb";
    // string sin = "wwwb\nbwbb\nbbbb\nbbbb";
    string sin; char c;
    while(cin >> c){sin += c;}

    string s = parseInput(sin);
    target = str2long(s);
    // cout << bitset<16> (target) << endl;

    int n = s.size();
    // cout << n << endl;
    int step, step_w, step_b;
    for (int i=0; i<n; i++){
        array.push_back(i);
    }
    for (int k=0; k<=n; k++){
        step_w = search(0, k, white);
        if (step_w != -1){
            // cout << '<' << state.size() << '>' << endl;
            state.clear();
            break;
        }
    }

    for (int k=0; k<=n; k++){
        step_b = search(0, k, black);
        if (step_b != -1){
            // cout << '<' << state.size() << '>' << endl;
            state.clear();
            break;
        }
    }

    if (step_b == -1){
        if (step_w == -1){
            step = -1;
        } else{
            step = step_w;
        }
    } else {
        if (step_w == -1){
            step = step_b;
        } else {
            step = min(step_b, step_w);
        }
    }

    if (step == -1){
        cout << "Impossible" << endl;
    } else {
        cout << step << endl;
        // for (int i=0; i<state.size(); i++){
        //     cout << state[i] << ' ';
        // }
        // cout << endl;
    }

    return 0;
}