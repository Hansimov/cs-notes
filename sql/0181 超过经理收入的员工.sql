/*
* 超过经理收入的员工 - 超过经理收入的员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/solution/chao-guo-jing-li-shou-ru-de-yuan-gong-by-leetcode/
*/

select a.name as `employee`
from employee as a
    join employee as b
on a.managerid = b.id
   and a.salary > b.salary
;
