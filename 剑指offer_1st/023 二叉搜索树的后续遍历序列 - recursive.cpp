/*

* 二叉搜索树的后序遍历序列__牛客网 
    * https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd

* 《剑指Offer》二叉搜索树的后序遍历序列_牛客博客 
    * https://blog.nowcoder.net/n/8fe97e67996249ccbe71328d3a49c4af?f=comment

*/

class Solution {
private:
    bool helper(vector<int> &v, int l_ptr, int r_ptr) {
        if (l_ptr>=r_ptr)
            return true;
        int sep_ptr=0;
        while(v[sep_ptr]<v[r_ptr])
            ++sep_ptr;
        for (int i=sep_ptr; i<r_ptr; ++i)
            if (v[i]<v[r_ptr])
                return false;
        return helper(v, l_ptr, sep_ptr-1) && helper(v, sep_ptr, r_ptr-1);
    }
public:
    bool VerifySquenceOfBST(vector<int> v) {
        if (v.empty()) return false;
        return helper(v, 0, v.size()-1);
    }
};