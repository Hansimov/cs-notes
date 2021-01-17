class Solution {
public:
    vector<string> res;
    string temp;

    void dfs(int n, int left, int right) {
        if (temp.size() == 2*n) {
            res.push_back(temp);
            return ;
        }

        if (left < n) {
            temp.push_back('(');
            dfs(n, left+1, right);
            temp.pop_back();
        }
        if (right < left) {
            temp.push_back(')');
            dfs(n, left, right+1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return res;
    }
};