/*
* 全排列 II - 全排列 II - 力扣（LeetCode）
    * https://leetcode-cn.com/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/
*/
class Solution {
    vector<int> visited;
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int idx, vector<int> &current) {
        if (idx==nums.size()) {
            res.emplace_back(current);
            // * C++ STL vector 添加元素（push_back()和emplace_back()）详解
            //   * http://c.biancheng.net/view/6826.html
            // push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；
            // 而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。
            return ;
        }

        for (int i=0; i<nums.size(); ++i) {
            // 哪些情况不取当前的元素：
            // 1. 已经访问过/在当前路径数组中
            // 2. 和前一个数相等，且前一个数未被填过（表明该数不是第一个未填的数，故仍然跳过）
            //    反过来理解，如果前一个相等的数已经被填过，那么此时就可以插入这后一个相等的数了，
            //    因为我们在上一层嵌套中，已经保证前一个数当时是第一个未被填过的数了
            //    此时意味着我们在当前路径数组中存在多个相等的数了
            if (visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1]))
                continue;
            current.emplace_back(nums[i]);
            visited[i] = true;
            backtrack(nums, res, idx+1, current);
            visited[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        visited.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0, current);
        return res;
    }
};