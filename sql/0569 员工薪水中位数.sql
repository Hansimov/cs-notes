/*
* 简洁窗口函数排序 - 员工薪水中位数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/median-employee-salary/solution/jian-ji-chuang-kou-han-shu-pai-xu-by-serenanio/
* MySQL DIV Function 
    * https://www.w3schools.com/sql/func_mysql_div.asp
*/

with t1 as (
    select id, company, salary,
        row_number() over (partition by company order by salary) as ranking,
        count(id) over (partition by company) as cnt
    from employee
)
select id, company, salary
from t1
where ranking>=cnt/2 and ranking<=cnt/2+1;