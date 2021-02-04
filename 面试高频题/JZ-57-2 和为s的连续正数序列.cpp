class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i=1, j=1;
        int sum=1;
        vector<vector<int>> res;

        while (i<=target/2) {
            if (sum == target) {
                vector<int> tmp;
                for (int k=i; k<=j; ++k) {
                    tmp.push_back(k);
                }
                res.push_back(tmp);
                sum -= i;
                ++i;
            } else if (sum<target) {
                ++j;
                sum += j;
            } else if (sum>target) {
                sum -= i;
                ++i;
            }
        }
        return res;
    }
};