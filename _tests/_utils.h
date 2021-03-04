#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator> // begin, end
#include <cstdarg>  // va_list, va_start, va_end, va_arg
#include <climits>  // INT_MIN, INT_MAX


// ===================================================== // 
template <typename T>
void disp(const std::vector<T> & v) {
    for (auto const &ele: v)
        std::cout << ele << " ";
    std::cout << std::endl;
}

// Python-like print in c++
//  https://gist.github.com/ilebedie/f006674098a1adaab731
// variadic functions - Variable number of arguments in C++? - Stack Overflow
//  https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c
// 省略号和可变参数模板 | Microsoft Docs
//  https://docs.microsoft.com/zh-cn/cpp/cpp/ellipses-and-variadic-templates
// Parameter pack(since C++11) - cppreference.com
//  https://en.cppreference.com/w/cpp/language/parameter_pack
// 可变参数模板 - 维基百科，自由的百科全书
//  https://zh.wikipedia.org/wiki/可变参数模板
// va_start和va_end使用详解 - Healtheon - 博客园
//  https://www.cnblogs.com/hanyonglu/archive/2011/05/07/2039916.html

void disp() {
    std::cout << std::endl;
}

template <typename T, typename ... REST>
void disp(const T & t, const REST & ... rest) {
    std::cout << t << " ";
    disp(rest...);
}

// ===================================================== // 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* constructLinkedList(const std::vector<int>&v, int cycle_pos = -1, bool is_dum = false) {
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
    while ((cycle_pos--)>=0) {
        tail->next = p;
        p = p->next;
    }
    if (is_dum)
        return dum;
    else
        return dum->next;
}

// ===================================================== // 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(const std::vector<int> & v, bool is_dum=false) {
    // TreeNode* root = new TreeNode(v[0]);
    if (v.size()==0) return nullptr;
    std::vector<TreeNode*> aq;  // last level nodes queue
    std::vector<TreeNode*> bq;  // current level nodes queue
    
    TreeNode* root = new TreeNode(v[0]);    // root node
    aq.push_back(root);

    int i = 1;                  // index of v
    int bq_max = 2*aq.size();   // max num of nodes at current level
    int bq_filled = 0;          // num of nodes already filled at current level
    int LR = 1;                 // 1: add to left child | 2: add to right child
    
    while (i<v.size()) {
        if (bq_filled < bq_max) {
            if (v[i] != INT_MIN) {
                TreeNode* tmp = new TreeNode(v[i]);
                bq.push_back(tmp);
                if (LR==1)
                    aq[bq_filled/2]->left = tmp;
                else
                    aq[bq_filled/2]->right = tmp;
            }
            // if (v[i] == nullptr), also runs the codes below
            ++i;
            ++bq_filled;
            LR = (LR==1) ? 2 : 1;
        } else {
            bq_filled = 0;
            bq_max = bq.size()*2;
            aq.clear();
            for (int i=0; i<bq.size(); ++i)
                aq.push_back(bq[i]);
            bq.clear();
        }
    }

    return root;
}