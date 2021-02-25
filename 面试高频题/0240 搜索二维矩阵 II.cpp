class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        if (row_num==0)
            return false;
        int col_num = matrix[0].size();

        int r = row_num-1, c = 0;
        int val;
        while (r>=0 && c<col_num) {
            val = matrix[r][c];
            if (val == target)
                return true;
            else if (val < target)
                ++c;
            else
                --r;
        }
        return false;
    }
};