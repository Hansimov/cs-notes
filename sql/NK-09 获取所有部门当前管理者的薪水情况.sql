select d.dept_no, d.emp_no, s.salary
from dept_manager as d
    inner join salaries as s
on d.emp_no = s.emp_no
where d.to_date = '9999-01-01'
    and s.to_date = '9999-01-01'
order by d.emp_no