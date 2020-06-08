/**
* Iterative Postorder Traversal | Set 2 (Using One Stack) - GeeksforGeeks 
    * https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        TreeNode *t = root;
        vector<int> v;
        stack<TreeNode *> s;
        while(true) {
            while(t) {
                s.push(t);
                s.push(t);
                t = t->left;
            }
            if (s.empty())
                break;
            t = s.top();
            s.pop();
            if (!s.empty() && t==s.top()) {
                t = t->right;
            } else {
                v.push_back(t->val);
                t = NULL;
            }
        }
        return v;
    }
};