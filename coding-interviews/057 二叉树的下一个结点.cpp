/*
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
        TreeLinkNode * t;
        if (pNode->right) {
            t = pNode->right;
            while (t && t->left)
                t = t->left;
            return t;
        } else { // pNode->right == NULL
            t = pNode->next;
            if (t==NULL) return NULL; // pNode is root and has no right children
            if (pNode == t->left) { // pNode is left child of parent
                return t;
            } else { // pNode==t->right && pNode->right==NULL
                while (t && t->next && t==t->next->right)
                    t = t->next;
                if (t==NULL)
                    return NULL;
                return t->next;
            }
        }
    }
};