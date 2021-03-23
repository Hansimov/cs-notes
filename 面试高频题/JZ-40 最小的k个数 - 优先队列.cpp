class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k==0)
            return {};
        vector<int> res;
        priority_queue<int> q; // default is max heap
        for (int i=0; i<k; ++i) {
            q.push(arr[i]);
        }
        for (int i=k; i<arr.size(); ++i) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};