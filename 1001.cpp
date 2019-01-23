/* 
- Link:
    http://poj.org/problem?id=1001&lang=default&change=true

- More test data:
    http://poj.org/showmessage?message_id=76017

==================================
Input  ---  Output

95.123 12 > 548815620517731830194541.899025343415715973535967221869852721
0.4321 20 > .00000005148554641076956121994511276767154838481760200726351203835429763013462401
5.1234 15 > 43992025569.928573701266488041146654993318703707511666295476720493953024
6.7592  9 > 29448126.764121021618164430206909037173276672
98.999 10 > 90429072743629540498.107596019456651774561044010001
1.0100 12 > 1.126825030131969720661201

*/

#include <iostream>
#include <vector>
#include <string>
// #include <cmath>
#include <algorithm>

using namespace std;

template <class T>
void coutv(vector<T> a){
    for (int i=0; i<a.size(); i++){
        cout << a[i];
    }
    cout << endl;
}

template <class T>
void reversev(vector<T> &v) {
    reverse(v.begin(), v.end());
    // coutv(v);
}

vector<int> mult(vector<int> a, vector<int> b) {
    int carry=0, sum=0;
    int c;

    reversev(a);
    reversev(b);

    vector<int> v(a.size()+b.size());
    for (int i=0; i<v.size(); i++){
        v[i] = 0;
    }

    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            c = a[i]*b[j] + carry + v[i+j];
            sum     = c%10;
            carry   = c/10;
            v[i+j] = sum;
        }
        v[i+b.size()] = carry;
        carry = 0;
    }

    reversev(v);

    return v;
}


vector<int> str2vec(string s){
    vector<int> v;
    for (int i=0; i<s.size(); i++){
        if (s[i] != '.') {
            v.push_back(s[i]-'0');
        }
    }
    return v;
}

// int str2int(string s){
//     int n=0;
//     for (int i=0; i<s.size(); i++){
//         n += (s[i]-'0') * pow(10, s.size()-i-1);
//     }
//     return n;
// }

int calcDeci(string s){
    int d=0;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '.'){
            d = s.size() - i - 1;
            break;
        }
    }
    return d;
}


string calcOutput(vector<int> v, int d, int p){
    string s;
    for (int i=0; i<v.size(); i++){
        s.append(1, v[i]+'0');
    }
    s.insert(s.end()-d*p,'.');
    return s;
}

string removeZeros(string &s){
    int head = 0;
    int tail = s.size();
    int len;

    for (int i=0; i<s.size(); i++){
        if (s[i] != '0'){
            head = i;
            break;
        }
    }

    for (int i=s.size()-1; i>=0; i--){
        if (s[i] != '0'){
            tail = i;
            break;
        }
    }

    len = tail - head + 1;
    string subs = s.substr(head, len);
    if (subs[len-1] == '.'){
        subs = subs.substr(0, len-1);
    }
    return subs;
}

int main(){
    string vin;
    int pin;
    while (cin >> vin >> pin){
        vector <int> v0 = str2vec(vin);
        int d = calcDeci(vin);
        // int p = str2int(pin);
        int p = pin;

        vector <int> v;
        v = v0;
        for (int i=1; i<p; i++){
            v = mult(v0, v);
        }

        // coutv(v);

        string s = calcOutput(v,d,p);
        // cout << s <<endl;

        cout << removeZeros(s) << endl;
    }

    return 0;
}