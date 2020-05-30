class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty()) return false;
        for (const auto &row: array) {
            if (find(row.begin(), row.end(), target) != row.end())
                return true;
        }
        return false;

    }
};