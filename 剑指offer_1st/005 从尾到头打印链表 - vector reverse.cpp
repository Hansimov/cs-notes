/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head == NULL) return {};
        vector<int> val_vec;
        ListNode *node = head;
        while(node!=NULL) {
            val_vec.push_back(node->val);
            node = node->next;
        }
        reverse(val_vec.begin(), val_vec.end());
        return val_vec;
    }
};