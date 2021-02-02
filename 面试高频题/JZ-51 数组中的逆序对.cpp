class Solution {
public:
    int merge_sort_sub(vector<int>& arr, vector<int>&tmp, int b, int e) {
        if (b>=e) return 0;
        // 分治并排序
        int b1 = b, e1 = b + (e-b)/2;
        int b2 = e1+1, e2 = e;
        int inv_cnt = merge_sort_sub(arr, tmp, b1, e1) + merge_sort_sub(arr, tmp, b2, e2);
        // 归并
        int i = b;
        while (b1<=e1 && b2<=e2) {
            if (arr[b1] <= arr[b2])
            // 必须用 <= 而非 <，因为要计入逆序必须满足 arr[b1] > arr[b2-1]，故取补集
                tmp[i++] = arr[b1++];
            else {
                tmp[i++] = arr[b2++];
                inv_cnt += ((e1+1)-b1); // 计入逆序对数
            }
        }
        while (b1<=e1)
            tmp[i++] = arr[b1++];
        while (b2<=e2)
            tmp[i++] = arr[b2++];
        copy(tmp.begin()+b, tmp.begin()+e+1, arr.begin()+b);
        return inv_cnt;
    }

    int merge_sort(vector<int>& arr) {
        vector<int> tmp(arr.size(), 0);
        return merge_sort_sub(arr, tmp, 0, arr.size()-1);
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums);
    }
};