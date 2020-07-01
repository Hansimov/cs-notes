/*

* C++ 解决办法 - 加油站 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/gas-station/solution/c-jie-jue-ban-fa-by-15091329223/

* 加油站 - 加油站 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/

* 【LeetCode】134. 加油站_一个有思想的搬运工-CSDN博客_leetcode 134 
    * https://blog.csdn.net/OneDeveloper/article/details/100049661

* LeetCode：加油站【134】 - MrSaber - 博客园 
    * https://www.cnblogs.com/MrSaver/p/9644679.html


*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty()) return -1;
        int sum = 0;
        int tmp_sum = 0;
        int res = 0;
        int sub;
        for (int i=0; i<gas.size(); ++i) {
            sub = gas[i] - cost[i];
            sum += sub;
            tmp_sum += sub;
            if (tmp_sum<0) {
                tmp_sum = 0;
                res = i+1;
            }
        }
        return sum < 0 ? -1 : res;
    }
};