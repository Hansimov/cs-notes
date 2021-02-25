#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        if (row_num == 0)
            return false;
        int col_num = matrix[0].size();

        int left = 0, right = row_num * col_num, mid;
        int idx, r, c, val;
        while (left < right) {
            mid = left + (right-left) / 2;
            r = mid / col_num;
            c = mid % col_num;
            val = matrix[r][c];
            if (val == target)
                return true;
            else if (val<target)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> vv1 = {{1,2,3},{4,5,6}};
    cout << sol.searchMatrix(vv1, 3) << endl;

    vector<vector<int>> vv2 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << sol.searchMatrix(vv2, 3) << endl;

    vector<vector<int>> vv3 = {{1,1}};
    cout << sol.searchMatrix(vv3, 0) << endl;

    return 0;
}