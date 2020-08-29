/*
* 图解SQL面试题：经典排名问题 - 分数排名 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/rank-scores/solution/tu-jie-sqlmian-shi-ti-jing-dian-pai-ming-wen-ti-by/
* 分成两个部分写会容易很多 - 分数排名 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/rank-scores/solution/fen-cheng-liang-ge-bu-fen-xie-hui-rong-yi-hen-duo-/
*/

select score,
    dense_rank() over(
        order by score desc
    ) as `rank`
from scores