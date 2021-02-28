class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (auto const &n: nums) {
            if (pq.size()==k)
                if (pq.top()>=n)
                    continue;
                else
                    pq.pop();
            pq.push(n);
        }
        return pq.top();
    }
};