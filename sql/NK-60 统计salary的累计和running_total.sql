/*
按照salary的累计和running_total，其中running_total为前N个当前(to_date = '9999-01-01')员工的salary累计和，其他以此类推。
*/

/*
把所有小于等于当前编号的表s1和当前编号表s2联立起来，然后按照当前编号分组，计算出所有小于等于
当前标号的工资总数
*/

/*
select s2.emp_no, s2.salary, sum(s1.salary) as running_total
from salaries as s1 
    join salaries as s2 
        on s1.emp_no <= s2.emp_no
where s1.to_date = "9999-01-01"
    and s2.to_date = "9999-01-01"
group by s2.emp_no
*/

select emp_no, salary,
    sum(salary) over (order by emp_no) as running_total
from salaries
where to_date = '9999-01-01';