#include <iostream>
#include <unordered_map>
#include <functional> // hash
#include <string>
#include <utility>    // pair

using namespace std;

struct pair_hash {
    template <typename T1, typename T2>
    int operator() (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        cout << h1 << " " << h2 << " " << (h1^h2) << endl;
        return h1 ^ h2;
    }
};

using Pair_UM = unordered_map<pair<int,int>, int, pair_hash>;

int main() {
    Pair_UM um;
    um[{1,1}] = 11;
    um[make_pair(1,1)] = 11;
    um[{1,2}] = 12;
    um[{1,4}] = 14;
    um[{12,4}] = 14;
    return 0;
}