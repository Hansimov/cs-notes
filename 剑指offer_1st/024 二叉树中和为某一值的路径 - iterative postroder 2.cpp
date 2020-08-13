/*

* 后序遍历求路径总和 - 路径总和 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/path-sum-ii/solution/hou-xu-bian-li-qiu-lu-jing-zong-he-by-watson-14/

* DFS非递归和递归python3 - 路径总和 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/path-sum-ii/solution/dfsfei-di-gui-python3-by-baiyizhe/

* Python solutions (Recursively, BFS+queue, DFS+stack) - LeetCode Discuss 
    * https://leetcode.com/problems/path-sum-ii/discuss/36829/Python-solutions-(Recursively-BFS%2Bqueue-DFS%2Bstack)

* C++ DFS 17ms non-recursive solution - LeetCode Discuss 
    * https://leetcode.com/problems/path-sum-ii/discuss/36843/C%2B%2B-DFS-17ms-non-recursive-solution

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root, int sum) {
        if (root==NULL) return {};
        vector<vector<int>> res;
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode *pre = NULL, *cur = root;

        while (cur!=NULL || !s.empty()) {
            while(cur!=NULL) {
                s.push(cur);
                sum -= cur->val;
                v.push_back(cur->val);
                cur = cur->left;
            }
            cur = s.top();
            if (cur->left==NULL && cur->right==NULL && sum==0) {
                res.push_back(v);
            }
            if (cur->right!=NULL && cur->right != pre) {
                cur = cur->right;
            } else {
                s.pop();
                sum += cur->val;
                v.pop_back();
                pre = cur;
                cur = NULL;
            }
        }
        return res;

    }
};