/*
* 一文搞懂《链表反转》 | lucifer的网络博客 
    * https://lucifer.ren/blog/2019/12/11/reverseList/
* 反转链表__牛客网 
    * https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca?answerType=1&f=discussion
* LeetCode 206——反转链表 - 简书 
    * https://www.jianshu.com/p/f7534f8d7bf2

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead==NULL) return NULL;
        ListNode *p_left = NULL;
        ListNode *p_mid = pHead;
        ListNode *p_right;
        while(p_mid != NULL) {
            p_right = p_mid->next;
            p_mid->next = p_left;
            p_left = p_mid;
            p_mid = p_right;
        }
        return p_left;
    }
};