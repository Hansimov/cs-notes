class Solution {
public:
    vector<string> res;
    string temp;

    void dfs(string& s, int cnt, vector<bool>& visited) {
        if (cnt==s.size()) {
            res.push_back(temp);
            return ;
        }
        for (int i=0; i<s.size(); ++i) {
            if (visited[i] || i>0 && s[i]==s[i-1] && !visited[i-1])
                continue;
            temp.push_back(s[i]);
            visited[i] = true;
            dfs(s, cnt+1, visited);
            visited[i] = false;
            temp.pop_back();
        }
    }

    vector<string> permutation(string s) {
        if (s.empty())
            return res;
        sort(s.begin(), s.end());
        vector<bool> visited(s.size(), false);
        dfs(s, 0, visited);
        return res;
    }
};