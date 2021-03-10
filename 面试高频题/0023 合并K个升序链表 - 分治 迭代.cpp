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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        int n = lists.size();
        for (int step=1; step<n; step*=2) {
            for (int i=step; i<n; i+=2*step) {
                lists[i-step] = mergeTwoLists(lists[i-step], lists[i]);
                lists[i] = nullptr;
            }
        }
        return lists[0];
    }
};