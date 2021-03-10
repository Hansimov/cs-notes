class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dum = new ListNode(-1);
        ListNode *p = dum;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dum->next;
    }

    ListNode* merge(vector<ListNode*> &lists, int L, int R) {
        if (L>R)
            return nullptr;
        if (L==R)
            return lists[L];
        int mid = L + (R-L)/2;
        return mergeTwoLists(merge(lists, L, mid), merge(lists, mid+1, R));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};