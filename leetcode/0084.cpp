#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
    if (heights.size()==0) return 0;

    int max_area=0, tmp_area=0;
    int min_height;
    int prev_height = 0;

    for (int i=0; i<heights.size(); ++i) {
        if (heights[i] > prev_height) {
            min_height = heights[i];
            for (int j=i; j<heights.size(); ++j) {
                if (j==heights.size()-1) {
                    tmp_area = min(heights[j], min_height) * (j-i+1);
                    if (tmp_area > max_area) {
                        max_area = tmp_area;
                    }
                }
                if (heights[j]<min_height) {
                    tmp_area = min_height * (j-i);
                    if (tmp_area > max_area) {
                        max_area = tmp_area;
                    }
                    min_height = heights[j];
                }
            }
        }
        prev_height = heights[i];
    }

    return max_area;
}
};

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0084.txt");

    int d;
    int c=0;
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
        // ++c;printf("==%d==\n", c);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    for (int i=0; i<vs.size(); ++i) {
        int r = largestRectangleArea(vn[i]);
        printf("%d\t%d\t%d\t%d\n", r==vr[i], 2*i+1, vr[i], r);
        // for (int j=0; j<vn[i].size(); ++j) {
        //     printf("\n%d", vn[i][j]);
        // }
    }

    return 0;
}