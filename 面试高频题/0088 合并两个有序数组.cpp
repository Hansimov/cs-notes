class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1;
        int p1 = m-1;
        int p2 = n-1;
        while (i>=0 && p1>=0 && p2>=0) {
            if (nums1[p1] > nums2[p2]) {
                swap(nums1[p1--], nums1[i--]);
            } else {
                swap(nums2[p2--], nums1[i--]);
            }
        }
        while (p2>=0)
            swap(nums2[p2--],nums1[i--]);
    }
};