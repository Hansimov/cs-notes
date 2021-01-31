class Solution {
public:
    bool recur(vector<int>& postorder, int left, int right) {
        if (left >= right)
            return true;
        int mid = left;
        int root = postorder[right];
        while (postorder[mid] < root) {
            ++mid;
        }
        int tmp = mid;
        while (tmp < right) {
            if (postorder[tmp++] < root) {
                return false;
            }
        }
        return recur(postorder, left, mid-1) && recur(postorder, mid, right-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }
};