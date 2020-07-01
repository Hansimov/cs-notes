/*

* Java O(n) solution using stack with detail explanation - LeetCode Discuss 
    * https://leetcode.com/problems/remove-duplicate-letters/discuss/76762/Java-O(n)-solution-using-stack-with-detail-explanation

* 去除重复字母 - 去除重复字母 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/remove-duplicate-letters/solution/qu-chu-zhong-fu-zi-mu-by-leetcode/

* c++ 0ms 击败100%，简明代码，超详细节解析 - 去除重复字母 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/remove-duplicate-letters/solution/c-0ms-ji-bai-100jian-ming-dai-ma-chao-xiang-xi-jie/

* java 栈实现 - 去除重复字母 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/remove-duplicate-letters/solution/java-zhan-shi-xian-by-5jiong-jie/

*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.size()==0) return s;
        unordered_map<char, int> last_idx_map;
        set<int> added_char_set;
        for (int i=0; i<s.size(); ++i)
            last_idx_map[s[i]] = i;

        string res("");
        for (int i=0; i<s.size(); ++i) {
            if (added_char_set.find(s[i]) == added_char_set.end()) {
                while (!res.empty() && res.back() > s[i] && last_idx_map[res.back()] > i) {
                    char char_to_pop = res.back();
                    res.pop_back();
                    added_char_set.erase(char_to_pop);
                }
                res.push_back(s[i]);
                added_char_set.insert(s[i]);
            }
        }
        return res;
    }
};