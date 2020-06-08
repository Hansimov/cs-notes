/**
* C++ Iterative, Recursive and Morris - LeetCode Discuss 
    * https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris
* Inorder Tree Traversal without Recursion - GeeksforGeeks 
    * https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

 lines of codes:
 中 2 1 1 2 3

/**
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        TreeNode *cur = root;
        vector<int> v;
        while(cur!=NULL) {
            if (cur->left==NULL) {
                v.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode *pre = cur->left;
                while(pre->right!=NULL && pre->right!=cur) {
                    // find the predecessor of of cur,
                    // which is the rightmost leaf node of cur->left
                    pre = pre->right;
                }
                if (pre->right==NULL) { // rightmost found and not linked
                    pre->right = cur;
                    cur = cur->left;
                } else  { // pre->right==cur
                    // this means the successor of pre has been linked,
                    // so this condition must happen when visiting node
                    //   instead of finding prev of cur
                    v.push_back(cur->val);
                    pre->right = NULL; // remove change of the node
                    cur = cur->right;
                }
            }
        }
        return v;
    }
};


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     int rightTag = 1;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 {(lvl,?):}