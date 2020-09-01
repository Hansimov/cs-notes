/*
据说（存疑）此题牛客网有问题，可见 Leetcode 同类题
* 184. 部门工资最高的员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-highest-salary/
* 185. 部门工资前三高的所有员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-top-three-salaries/
*/

with t as (
    select d.dept_no, max(s.salary) as max_salary
    from dept_emp as d
        join salaries as s
    on d.emp_no = s.emp_no
    where d.to_date = '9999-01-01'
        and s.to_date = '9999-01-01'
    group by d.dept_no
)
select t.dept_no, ss.emp_no, t.max_salary
from t, salaries as ss, dept_emp as dd
where ss.salary = t.max_salary
    and dd.dept_no = t.dept_no
    and dd.emp_no = ss.emp_no
    and ss.to_date = '9999-01-01'
    and dd.to_date = '9999-01-01'
order by t.dept_no asc