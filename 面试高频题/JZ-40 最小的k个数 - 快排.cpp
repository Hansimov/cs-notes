class Solution {
public:
    int random_partition(vector<int> &arr, int L, int R) {
        int pivot = rand() % (R-L+1) + L;
        swap(arr[pivot], arr[R]);
        int last = arr[R];
        int i = L;
        for (int j=L; j<R; ++j) {
            if (arr[j] < last)
                swap(arr[j], arr[i++]);
        }
        swap(arr[i], arr[R]);
        return i;
    }

    void random_select(vector<int> &arr, int L, int R, int k) {
        if (L>=R) return;
        int q = random_partition(arr, L, R);
        if (q == k)
            return;
        else if (q<k)
            random_select(arr, q+1, R, k);
        else
            random_select(arr, L, q-1, k);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        random_select(arr, 0, arr.size()-1, k);
        for (int i=0; i<k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
};