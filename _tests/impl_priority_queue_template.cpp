#include "_utils.h"
#include <vector>
#include <iterator>     // distance
#include <functional>   // function, less, greater
#include <queue>        // queue, priority_queue

template <typename T = int, typename Iter = typename std::vector<T>::iterator, typename Compare = std::less<T>>
void make_heap(Iter first, Iter last, Compare cmp) {

}

template <typename T = int, typename Iter = typename std::vector<T>::iterator, typename Compare = std::less<T>>
void push_heap(Iter first, Iter last, Compare cmp) {

}

template <typename T = int, typename Iter = typename std::vector<T>::iterator, typename Compare = std::less<T>>
void pop_heap(Iter first, Iter last, Compare cmp) {
    
}

template <typename T = int, typename Sequence = std::vector<T>, typename Compare = std::less<T>>
class my_priority_queue {
private:
    Sequence v;
    Compare cmp;
    std::vector<T>::size_t size = 0;

public:
    my_priority_queue() : v() {}

    my_priority_queue(typename Sequence::iterator first, typename Sequence::iterator last, const Compare & cmp)
    : v(first, last), cmp(cmp) {
        make_heap(v.begin(), v.end(), cmp);
    }

    typename Sequence::iterator top() const {
        return v.front();
    }

    void push(const T &t) {
        v.push_back(t);
        push_heap(v.begin(), v.end(), cmp);
    }

    void pop() {
        pop_heap(v.begin(), v.end(), cmp);
        v.pop_back();
    }

};

int main() {
    my_priority_queue<int, std::vector<int>, std::less<int>> pq;

    return 0;
}