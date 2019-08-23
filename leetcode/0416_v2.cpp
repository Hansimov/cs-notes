/*
- 0/1 knapsack detailed explanation - LeetCode Discuss 
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
- Simple C++ 4-line solution using a bitset - LeetCode Discuss 
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C%2B%2B-4-line-solution-using-a-bitset
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C++-4-line-solution-using-a-bitset/94973
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C++-4-line-solution-using-a-bitset/296454
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <limits.h>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum&1) return false;
    bitset<10001> bits(1);
    // bits[s]: whether sum s can be gotton from nums
    for (auto n : nums) bits |= bits << n;
    return bits[sum >> 1];
}

string filename = "0416.txt";
const auto& myFunc = canPartition;

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        stringstream ss(sin);

        vector<int> vni = {};
        while (ss >> d) {
            vni.push_back(d);
        }
        vn.push_back(vni);

        getline(fp, rin, '\n');
        vr.push_back(stoi(rin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        bool res = myFunc(vn[i]);
        bool is_correct = (int)res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}