class Solution {
public:
    vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    // check(i,j,k,...): is exist a path starts from board[i][j] matches word[k:]
    bool check(int i, int j, int k, vector<vector<char>> &board, vector<vector<bool>> &visited, string &word) {
        if (board[i][j] != word[k])
            return false;
        else if (k==word.length()-1)
            return true;

        visited[i][j] = true;
        bool tmp_flag = false;
        for (const auto& d: directions) {
            int i_new = i + d.first;
            int j_new = j + d.second;
            if (i_new>=0 && i_new<board.size() && j_new>=0 && j_new<board[0].size()) {
                if (visited[i_new][j_new])
                    continue;
                tmp_flag = check(i_new, j_new, k+1, board, visited, word);
                if (tmp_flag) {
                    visited[i][j] = false;
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row_num = board.size();
        if (row_num<=0)
            return false;
        int col_num = board[0].size();
        bool flag = false;
        vector<vector<bool>> visited(row_num, vector<bool>(col_num));
        for (int i=0; i<row_num; ++i) {
            for (int j=0; j<col_num; ++j) {
                flag = check(i, j, 0, board, visited, word);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};