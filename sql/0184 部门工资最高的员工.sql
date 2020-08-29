/*
* 部门工资最高的员工 - 部门工资最高的员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-highest-salary/solution/bu-men-gong-zi-zui-gao-de-yuan-gong-by-leetcode/
*/

select department.name as `department`, employee.name as `employee`, employee.salary as `salary`
from employee join department
on employee.departmentid = department.id
where (
    (employee.departmentid, employee.salary) in (
        select departmentid, max(salary)
        from employee
        group by departmentid
    )
)
