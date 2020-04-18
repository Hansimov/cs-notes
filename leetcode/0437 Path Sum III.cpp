// * C++ solution with prefix sum stored in hash table - LeetCode Discuss 
// ** https://leetcode.com/problems/path-sum-iii/discuss/91908/C%2B%2B-solution-with-prefix-sum-stored-in-hash-table

// * 17 ms O(n) java Prefix sum method - LeetCode Discuss 
// ** https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method

// * 前缀和，递归，回溯 - 路径总和 III - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/path-sum-iii/solution/qian-zhui-he-di-gui-hui-su-by-shi-huo-de-xia-tian/

// * 18ms Fast One Pass C++ Solution - LeetCode Discuss 
// ** https://leetcode.com/problems/path-sum-iii/discuss/91888/18ms-Fast-One-Pass-C%2B%2B-Solution

// * 两种方法 简单易懂版本 - 路径总和 III - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/path-sum-iii/solution/liang-chong-fang-fa-jian-dan-yi-dong-ban-ben-by-a3/

// * C++ 5 Line Body Code DFS Solution - LeetCode Discuss 
// ** https://leetcode.com/problems/path-sum-iii/discuss/91877/C%2B%2B-5-Line-Body-Code-DFS-Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> pre_sum_map;
        pre_sum_map[0] = 1;

        int res = 0;
        helper(root,0,sum,res,pre_sum_map);
        return res;
    }

    void helper(TreeNode* t, int cur_sum, int sum, int &res, unordered_map <int,int> &pre_sum_map) {
        if (t==NULL)
            return;

        cur_sum += t->val;
        if (pre_sum_map.find(cur_sum-sum) != pre_sum_map.end())
            res += pre_sum_map[cur_sum-sum];

        pre_sum_map[cur_sum]++;

        helper(t->left, cur_sum, sum, res, pre_sum_map);
        helper(t->right, cur_sum, sum, res, pre_sum_map);

        pre_sum_map[cur_sum]--;
    }
};