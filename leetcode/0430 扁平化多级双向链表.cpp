/*

* C++详细题解DFS: 递归法&Stack双解+代码注释 - 扁平化多级双向链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/cxiang-xi-ti-jie-die-dai-fa-dai-ma-zhu-shi-by-youl/


* C++：迭代法（代码简单，逻辑清晰） - 扁平化多级双向链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/cdie-dai-fa-dai-ma-jian-dan-luo-ji-qing-xi-by-xiao/

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head==NULL) return NULL;
        stack<Node*> s;
        s.push(head);
        Node* cur;
        Node* pre = NULL;

        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur->next) {
                s.push(cur->next);
            }
            if (cur->child) {
                s.push(cur->child);
                cur->child = NULL;
            }
            if (pre) {
                pre->next = cur;
                cur->prev = pre;
            }
            pre = cur;
        }
        return head;
    }
};