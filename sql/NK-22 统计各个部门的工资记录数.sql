with t as (
    select de.dept_no, s.salary
    from dept_emp as de
        join salaries as s
    on de.emp_no = s.emp_no
)
select t.dept_no, d.dept_name, count(t.salary) as sum
from t
    join departments as d
on t.dept_no = d.dept_no
group by t.dept_no