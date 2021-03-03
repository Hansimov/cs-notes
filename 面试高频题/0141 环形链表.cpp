#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * constructLinkedList(const vector<int>&v, int pos = -1) {
    // construct linked list
    ListNode *dum = new ListNode(0);
    ListNode *p = new ListNode(v[0]);
    dum->next = p;
    ListNode *tail;
    for (int i=1; i<v.size(); ++i) {
        p->next = new ListNode(v[i]);
        p = p->next;
        tail = p;
    }
    // tail node point to node
    p = dum->next;
    while (pos-->=0) {
        tail->next = p;
        p = p->next;
    }
    return dum;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            if (fast->next==NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main() {
    vector<int> v = {3,2,0,-4};
    int pos = 1;
    ListNode *dum = constructLinkedList(v, pos);
    // print linked list
    int cnt = 0;
    ListNode *p = dum->next;
    while (cnt++<=v.size() && p) {
        if (cnt==v.size()+1)
            cout << "> ";
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    // check has cycle
    Solution sol;
    cout << "hasCycle: " << (sol.hasCycle(dum->next) ? "True" : "False") << endl;

    delete p;
    return 0;
}