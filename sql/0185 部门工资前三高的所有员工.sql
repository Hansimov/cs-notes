/*
* 窗口函数+三表连接 - 部门工资前三高的所有员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-top-three-salaries/solution/chuang-kou-han-shu-san-biao-lian-jie-by-hui-tiao-d/
* 图解SQL面试题：经典TOPN问题 - 部门工资前三高的所有员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-top-three-salaries/solution/tu-jie-sqlmian-shi-ti-jing-dian-topnwen-ti-by-houz/
* 185. 部门工资前三高的员工 - 部门工资前三高的所有员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-top-three-salaries/solution/185-bu-men-gong-zi-qian-san-gao-de-yuan-gong-by-li/
*/

select d.name as `department`, e.name as `employee`, e.salary as `salary`
from employee as e,
    department as d,
    (select id,
        dense_rank() over (
            partition by departmentid
            order by salary desc) as ranking
    from employee
    ) as c
where e.departmentid = d.id
    and e.id = c.id
    and c.ranking <= 3;