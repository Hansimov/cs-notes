class Solution {
public:
    unordered_map<int, int> map;
    vector<int> pre;

    TreeNode* recur(int pb, int ib, int ie) {
        if (pb<pre.size() && ib<=ie) {
            auto t = new TreeNode(pre[pb]);
            int L_pb = pb+1;
            int L_ib = ib;
            int R_ie = ie;
            int L_ie = map[t->val]-1;
            int R_ib = map[t->val]+1;
            int R_pb = pb + (L_ie - L_ib + 1) + 1;
            
            t->left  = recur(L_pb, L_ib, L_ie);
            t->right = recur(R_pb, R_ib, R_ie);
            return t;
        }
        return nullptr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); ++i)
            map[inorder[i]] = i;
        pre = preorder;
        return recur(0, 0, inorder.size()-1);
    }
};