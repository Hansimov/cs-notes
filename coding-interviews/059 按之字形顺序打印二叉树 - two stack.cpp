/*

* [c++] 5ms version: one queue and without reverse operation by using size of each level - LeetCode Discuss 
    * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/33825/c%2B%2B-5ms-version%3A-one-queue-and-without-reverse-operation-by-using-size-of-each-level
    
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot==NULL) return {};
        vector<vector<int>> res;
        stack<TreeNode*> s, s_r;
        TreeNode *t;
        bool to_reverse = false;
        
        s.push(pRoot);
        while (!s.empty() || !s_r.empty()) {
            vector<int> v;
            if (!s.empty()) {
                while(!s.empty()) {
                    t = s.top();
                    s.pop();
                    v.push_back(t->val);
                    if (t->left)
                        s_r.push(t->left);
                    if (t->right)
                        s_r.push(t->right);
                }
                res.push_back(v);
            } else if (!s_r.empty()) {
                while (!s_r.empty()) {
                    t = s_r.top();
                    s_r.pop();
                    v.push_back(t->val);
                    if (t->right)
                        s.push(t->right);
                    if (t->left)
                        s.push(t->left);
                }
                res.push_back(v);
            }
        }
        return res;
    }
    
};