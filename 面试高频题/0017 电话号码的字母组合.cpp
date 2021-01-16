class Solution {
public:
    vector<string> res;
    string temp;
    vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(int digit_idx, string& digits) {
        if (digit_idx == digits.size()) {
            res.push_back(temp);
            return ;
        }

        int board_idx = digits[digit_idx] - '0';
        for (int i=0; i<board[board_idx].size(); ++i) {
            temp.push_back(board[board_idx][i]);
            dfs(digit_idx+1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;
        dfs(0, digits);
        return res;
    }
};