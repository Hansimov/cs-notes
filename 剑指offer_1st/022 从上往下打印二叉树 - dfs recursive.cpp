/*

* 迭代+递归 多图演示 102.二叉树的层次遍历 - 二叉树的层序遍历 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/die-dai-di-gui-duo-tu-yan-shi-102er-cha-shu-de-cen/

* 套模板！BFS 和 DFS 都可以解决 - 二叉树的层序遍历 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/tao-mo-ban-bfs-he-dfs-du-ke-yi-jie-jue-by-fuxuemin/

* 从上往下打印二叉树__牛客网 
    * https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701?answerType=1&f=discussion

* Level Order Tree Traversal - GeeksforGeeks 
    * https://www.geeksforgeeks.org/level-order-tree-traversal/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
private:
    void helper(vector<vector<int>> &vv, TreeNode *t, int level) {
        if (t==NULL) return ;
        if (level>=vv.size())
            vv.push_back(vector<int>{});
        vv[level].push_back(t->val);

        helper(vv, t->left,  level+1);
        helper(vv, t->right, level+1);

    }
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root==NULL) return {};
        vector<vector<int>> vv;
        helper(vv, root, 0);
        vector<int> v;
        
        for (auto &row: vv) {
            v.insert(v.end(), row.begin(), row.end());
        }

        return v;
    }
};