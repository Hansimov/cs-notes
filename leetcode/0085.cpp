// Maximum size rectangle binary sub-matrix with all 1s
//   https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

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

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); // Terminator
    stack<int> st;
    int max_area=0;
    int ptr=0;

    for (int i=0; i<heights.size(); ++i) {
        if (st.empty() || heights[i] > heights[st.top()] ) {
            st.push(i);
        } else {
            ptr = st.top();
            st.pop();
            max_area = max(max_area, heights[ptr]*(st.empty()?i:i-st.top()-1));
            --i; // Important! To check all previous higher histogram.
        }
    }

    return max_area;
}

class Solution {
public:
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size()==0)
        return 0;

    int max_area=0;
    vector<int> row;
    int rownum = matrix.size();
    int colnum = matrix[0].size();

    for (int j=0; j<colnum; ++j) {
        row.push_back(0);
    }

    for (int i=0; i<rownum; ++i) {
        for (int j=0; j<colnum; ++j) {
            if (matrix[i][j]=='0')
                row[j] = 0;
            else
                row[j] += 1;
        }
        max_area = max(max_area, largestRectangleArea(row));
    }
    return max_area;
}
};

int main() {
    string sin;
    int row, col, rr, state;
    vector<vector<vector<char>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open("0085.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> rr;
        vr.push_back(rr);
        vg.push_back({});
        for (int i=0; i<row; ++i) {
            getline(fp, sin, '\n');
            stringstream ss(sin);
            vg.back().push_back({});
            for (int j=0; j<col; ++j) {
                ss >> state;
                vg.back()[i].push_back('0'+state);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = maximalRectangle(vg[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += vg[i].size()+1;
    }

    return 0;
}