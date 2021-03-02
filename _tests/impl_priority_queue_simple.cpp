#include "_utils.h"
#include <vector>
#include <iterator>     // distance
#include <functional>   // function, less, greater
#include <queue>        // queue, priority_queue

template <typename Comparator> // less<int> is max heap
class my_priority_queue {
public:
    std::vector<int> v;
    Comparator cmp;

    my_priority_queue() : v() {
        v.push_back(-1);
    }

    int get_parent_idx(int c_idx) {
        return c_idx / 2;
    }

    void push(const int & t) {
        v.push_back(t);
        int c_idx = v.size()-1;
        int p_idx = c_idx/2;
        while (c_idx>1 && cmp(v[p_idx], v[c_idx])) {
            std::swap(v[p_idx], v[c_idx]);
            c_idx = p_idx;
            p_idx = c_idx/2;
        }
    }

    int get_vip_child_idx(int p_idx) {
        int c_idx = p_idx*2;
        if (c_idx < v.size()-1 && cmp(v[c_idx], v[c_idx+1]))
            ++c_idx;
        return c_idx;
    }

    int pop() {
        int root_val = v[1];
        int back_val = v[v.size()-1];
        std::swap(v[1], v[v.size()-1]);
        v.pop_back();

        int p_idx = 1;
        int c_idx = get_vip_child_idx(p_idx);
        while (c_idx < v.size() && cmp(v[p_idx], v[c_idx])) {
            std::swap(v[p_idx], v[c_idx]);
            p_idx = c_idx;
            c_idx = get_vip_child_idx(p_idx);
        }
        return root_val;
    }

    int top() {
        return v[1];
    }

    int size() {
        return v.size()-1;
    }
};

int main() {
    my_priority_queue<std::greater<int>> pq;
    std::vector<int> v = {2,1,5,6,4,3};
    for (auto const & ele: v) {
        pq.push(ele);
        disp(pq.v);
    }
    std::cout << std::endl;
    disp(pq.top(), pq.size());
    while (pq.v.size()>1) {
        std::cout << pq.pop() << " ";
        disp(pq.v);
    }
    return 0;
}