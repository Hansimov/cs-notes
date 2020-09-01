with t as (
    select s1.salary
    from salaries as s1
        left join salaries as s2
    on s1.salary <= s2.salary
    where s1.to_date = '9999-01-01'
        and s2.to_date = '9999-01-01'
    group by s1.salary
    having count(distinct s2.salary)=2
)
select e.emp_no, s.salary, e.last_name, e.first_name
from employees as e
    left join salaries as s
on e.emp_no = s.emp_no
where s.to_date = '9999-01-01'
    and s.salary in t