/**

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty()) return NULL;
        TreeNode *t = new TreeNode(pre[0]);
        auto vin_itr = find(vin.begin(), vin.end(), t->val);

        vector<int> vin_left = vector<int>(vin.begin(), vin_itr);
        vector<int> vin_right = vector<int>(vin_itr+1, vin.end());

        vector<int> pre_left = vector<int>(pre.begin()+1, pre.begin()+1+vin_left.size());
        vector<int> pre_right = vector<int>(pre.begin()+1+vin_left.size(), pre.end());

        t->left  = reConstructBinaryTree(pre_left ,vin_left);
        t->right = reConstructBinaryTree(pre_right ,vin_right);
        return t;
    }
};