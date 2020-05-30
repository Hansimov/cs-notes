/*
* CodingInterviews/003-二维数组中的查找 at master · gatieme/CodingInterviews 
    * https://github.com/gatieme/CodingInterviews/tree/master/003-二维数组中的查找

* 二维数组中的查找__牛客网 
    * https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e

对于数组中的任何一个元素, 比它小的元素都在它的左方或者上方, 比它大的元素都在它的右边或者下方

但是这两个区域还有可能有重叠，比如右边或下边会在右下角有重叠。
为了不重复的处理重叠的数据, 我们要找几个特殊的起点, 保证每次比较后能剔除掉一列或者一行，或者说，确定其他方向没有符合条件的数。

从左上往右下，那么如果target大于该数，则不能确定往右还是往下（因为都符合），从右下往左上亦然。
从右上往左下，如果target大于该数，必往下，如果target小于该数，必往左。相等则返回true。如果到达边界（大的不能继续往下，小的不能继续往左），则返回false。

复杂度：O(m+n)，m为行数，n为列数

*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty()) return false;
        int r=0, c=array[0].size()-1;
        while (r<=array.size()-1 && c>=0) {
            if (array[r][c]==target)
                return true;
            else
                if (array[r][c]<target)
                    ++r;
                else
                    --c;
        }
        return false;
    }
};