/*

* 二叉树的下一个结点__牛客网 
    * https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode==NULL) return NULL;
        TreeLinkNode * t=pNode;
        if (t->right) {
            t = t->right;
            while (t && t->left)
                t = t->left;
            return t;
        }
        while(t->next) {
            if (t->next->left==t)
                return t->next;
            t = t->next;
        }
        return NULL;
    }
};