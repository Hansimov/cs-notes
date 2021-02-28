class Solution {
public:
    int rand_partition(vector<int> & a, int L, int R) {
        // choose random num in [L,R] as pivot
        int pivot = rand()%(R-L+1)+L;
        swap(a[pivot], a[R]); // put a[pivot] to last
        int last = a[R];
        // search correct order-index of a[pivot] from L
        int i = L; // i: the correct index of a[pivot]
        for (int j=L; j<R; ++j)
            if (a[j] < last)
                // increment i to mark num of elements smaller than a[pivot]
                swap(a[j], a[i++]);
        // put a[pivot] to a[i]
        swap(a[i], a[R]);
        return i;
    }

    int quick_select(vector<int>& a, int L, int R, int idx) {
        int q = rand_partition(a, L, R);
        if (q == idx)
            return a[q];
        else {
            if (q < idx)
                return quick_select(a, q+1, R, idx);
            else
                return quick_select(a, L, q-1, idx);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        time_t t;
        srand((unsigned) time(&t));
        return quick_select(nums, 0, nums.size()-1, nums.size()-k);
    }
};