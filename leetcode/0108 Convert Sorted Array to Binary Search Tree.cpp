// * 16 ms C++ solution - LeetCode Discuss 
// ** https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/35242/16-ms-C%2B%2B-solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>&nums, int start, int end){
        if (start>end) 
            return NULL;
        int mid = (start+end)/2;
        TreeNode* t = new TreeNode(nums[mid]);
        t->left = helper(nums,start,mid-1);
        t->right = helper(nums,mid+1,end);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};