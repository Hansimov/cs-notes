class Solution {
public:
    string minNumber(vector<int>& nums) {vector<string> vs;
        string res;
        for (auto const &n: nums) {vs.push_back(to_string(n));
        }

        sort(vs.begin(), vs.end(), 
            [](string& s1, string& s2) {return s1+s2 < s2+s1;  // if condition is true, then s1 < s2}
        );

        for (auto const &s: vs) {res += s;}
        return res;
    }
};