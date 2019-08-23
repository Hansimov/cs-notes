#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <limits.h>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    if (n<=2) return 0;
    vector<int> diffs(A.size()-1,0);
    for (int i=0; i<n-1; ++i) {
        diffs[i] = A[i+1] - A[i];
    }

    vector<int> nums = {};
    int prev = diffs[0];
    int cnt = 1;
    for (int i=1; i<diffs.size(); ++i) {
        if (diffs[i]==prev) {
            cnt++;
            if (i==n-2) {
                nums.push_back(cnt);
            }
        } else {
            if (cnt>=2) {
                nums.push_back(cnt);
            }
            cnt = 1;
            prev = diffs[i];
        }
    }

    int res = 0;
    for (int num:nums) {
        res += num*(num-1)/2;
    }

    return res;
}

string filename = "0413.txt";
const auto& myFunc = numberOfArithmeticSlices;

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
            // printf("%d ", d);
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
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}