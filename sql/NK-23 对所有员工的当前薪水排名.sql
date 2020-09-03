/*
select emp_no, salary, 
    dense_rank() over (order by salary desc) as `rank`
where to_date = '9999-01-01'
order by salary desc, emp_no asc
*/

select s1.emp_no, s1.salary, count(distinct s2.salary) as `rank`
from salaries as s1, salaries as s2
where s1.to_date = '9999-01-01'
    and s2.to_date = '9999-01-01'
    and s1.salary <= s2.salary
group by s1.emp_no -- 必须加上，表示对每个 s1 得到不小于 s1 的 s2 的薪水的去重后的个数，否则只会输出一条，因为用了合计函数 count()
order by s1.salary desc, s1.emp_no asc