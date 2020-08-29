/*
* SQL SERVER 解法 - 连续出现的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/consecutive-numbers/solution/sql-server-jie-fa-by-neilsons/

* 编写一个 SQL 查询，查找所有至少连续出现三次的数字。 - 连续出现的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/consecutive-numbers/solution/bian-xie-yi-ge-sql-cha-xun-cha-zhao-suo-you-zhi-sh/
* 连续出现的数字 - 连续出现的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/consecutive-numbers/solution/lian-xu-chu-xian-de-shu-zi-by-leetcode/
*/

select distinct num as ConsecutiveNums
from (
    select num,
        if(@pre=num, @cnt:=@cnt+1, @cnt:=1) as count,
        @pre:=num
    from Logs as lg, (select @pre:=null, @cnt:=1) as pre_cnt
    -- 上面这段代码执行结果就是一张三列为Num, cnt as count, pre的表。
) as n
where count >= 3;