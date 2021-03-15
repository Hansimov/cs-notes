class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)
            return false;
        unordered_map<char,char> mp = {
            {')', '('},
            {'}', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char c: s) {
            if ()
        }

    }
};