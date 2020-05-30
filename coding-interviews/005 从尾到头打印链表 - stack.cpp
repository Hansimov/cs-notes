/*
* 从尾到头打印链表__牛客网 
    * https://www.nowcoder.com/questionTerminal/d0267f7f55b3412ba93bd35cfa8e8035

*/

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
        if (head==NULL) return {};
        stack<int> stk;
        vector<int> res;

        while(head!=NULL) {
            stk.push(head->val);
            head = head->next;
        }
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};