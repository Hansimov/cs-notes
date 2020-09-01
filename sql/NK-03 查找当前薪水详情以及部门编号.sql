select s.*, d.dept_no
from salaries as s
    left join dept_manager as d
on s.emp_no = d.emp_no
where s.to_date = '9999-01-01'
    and d.to_date = '9999-01-01'
