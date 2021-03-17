class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)
            return false;
        unordered_map<char,char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (mp.find(ch)!=mp.end()) { // right half
                if (stk.empty() || stk.top()!=mp[ch])
                    return false;
                else
                    stk.pop();
            } else { // left half
                stk.push(ch);
            }
        }
        return stk.empty(); // is any left half still in stack
    }
};