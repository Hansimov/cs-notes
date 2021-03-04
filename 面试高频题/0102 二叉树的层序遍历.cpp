#include "../_tests/_utils.h"
#include <deque>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        deque<TreeNode*> q;
        q.push_back(root);

        while(!q.empty()) {
            int current_level_size = q.size();
            vector<int> v;
            for (int i=0; i<current_level_size; ++i) {
                auto t = q.front();
                v.push_back(t->val);
                q.pop_front();
                if (t->left)
                    q.push_back(t->left);
                if (t->right)
                    q.push_back(t->right);
            }
            res.push_back(v);
        }
        return res;
    }
};

void preorder(TreeNode* root) {
    if (root==nullptr)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> v = {3,9,20,INT_MIN,INT_MIN,15,7};
    // vector<int> v = {1,2,3,INT_MIN,4,5,6,7,INT_MIN};
    TreeNode *root = constructTree(v);
    // disp(root->val);
    // preorder(root);
    Solution sol;
    vector<vector<int>> vv = sol.levelOrder(root);
    for (auto & v : vv) {
        for (auto & ele : v)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}