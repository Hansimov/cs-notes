class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> s;
        for (auto const & ele: nums) {
            if (ele==0)
                continue;
            if (s.count(ele))
                return false;
            s.insert(ele);
        }
        if (*s.rbegin()-*s.begin()>=5)
            return false;
        return true;
    }
};