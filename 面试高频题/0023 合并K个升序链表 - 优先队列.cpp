class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto & ele: lists)
            if (ele)
                q.push(ele);

        ListNode* dum = new ListNode(-1);
        ListNode* cur = dum;
        while (!q.empty()) {
            cur->next = q.top();
            cur = cur->next;
            q.pop();
            if (cur->next)
                q.push(cur->next);
        }
        return dum->next;
    }
};