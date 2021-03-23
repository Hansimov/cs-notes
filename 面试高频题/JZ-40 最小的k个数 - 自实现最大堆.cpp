#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        return a < b; // max heap
    }

    void heapify(vector<int> &a, int i, int r_bound, bool (*cmp)(int, int)) {
        while (2*i+1 <= r_bound) {
            int L = 2*i + 1;
            int R = 2*i + 2;

            // get greater idx
            int greater_idx;
            if (L<=r_bound && cmp(a[i], a[L]))
                greater_idx = L;
            else
                greater_idx = i;
            if (R<=r_bound && cmp(a[greater_idx], a[R]))
                greater_idx = R;

            // if parent greater than both child, break
            if (greater_idx == i)
                break;
            else {
                swap(a[greater_idx], a[i]);
                i = greater_idx;
            }
        }
    }

    void build_heap(vector<int> &a, bool (*cmp)(int,int)) {
        int len = a.size();
        for (int i=(len-1)/2; i>=0; --i) {
            heapify(a, i, len-1, cmp);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k==0) return {};
        vector<int> q(arr.begin(), arr.begin()+k);
        build_heap(q, cmp);
        for (int i=k; i<arr.size(); ++i) {
            if (arr[i] < q[0]) {
                q[0] = arr[i];
                heapify(q, 0, k-1, cmp);
            }
        }

        vector<int> res;
        for (int i=0; i<k; ++i)
            res.push_back(q[i]);

        return res;
    }
};

int main() {
    // vector<int> arr = {7,3,2,1,4,0,6};
    // int k = 3;
    vector<int> arr = {3,2,1};
    int k =2;
    Solution sol;
    vector<int> res = sol.getLeastNumbers(arr, k);
    for (auto const &x: res)
        cout << x << " ";
    cout << endl;
    
    return 0;
}