template <typename Comparator>
class my_priority_queue {
public:
    vector<int> v;
    Comparator cmp;

    my_priority_queue() : v() {
        v.push_back(-1);
    };

    void push(const int & t) {
        v.push_back(t);
        int c_idx = v.size()-1;
        int p_idx = c_idx/2;
        while (c_idx > 1 && cmp(v[p_idx], v[c_idx])) {
            swap(v[p_idx], v[c_idx]);
            c_idx = p_idx;
            p_idx = c_idx/2;
        }
    }

    int get_vip_chiled_idx(int p_idx) {
        int c_idx = p_idx * 2;
        if (c_idx<v.size()-1 && cmp(v[c_idx], v[c_idx+1]))
            ++c_idx;
        return c_idx;
    }

    int pop() {
        int root_val = v[1];
        int back_val = v[v.size()-1];
        swap(v[1], v[v.size()-1]);
        v.pop_back();

        int p_idx = 1;
        int c_idx = get_vip_chiled_idx(p_idx);
        while (c_idx<v.size() && cmp(v[p_idx], v[c_idx])) {
            swap(v[p_idx], v[c_idx]);
            p_idx = c_idx;
            c_idx = get_vip_chiled_idx(p_idx);
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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        my_priority_queue<greater<int>> pq; // greater: min heap
        for (auto const & n : nums) {
            if (pq.size()==k)
                if (pq.top() >= n)
                    continue;
                else
                    pq.pop();
            pq.push(n);
        }
        return pq.top();
    }
};