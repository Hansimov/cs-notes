select t.title, avg(s.salary) as `avg`
from titles as t
    left join salaries as s
on t.emp_no = s.emp_no
where t.to_date = '9999-01-01'
    and s.to_date = '9999-01-01'
group by title