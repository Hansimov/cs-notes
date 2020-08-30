/*
* 577. 员工奖金 - 员工奖金 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/employee-bonus/solution/577-yuan-gong-jiang-jin-by-eric-345/
*/

select e.name, b.bonus
from employee as e
    left join bonus as b
on e.empid = b.empid
where bonus is null or bonus < 1000