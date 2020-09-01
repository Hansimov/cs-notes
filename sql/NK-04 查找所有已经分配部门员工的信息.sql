select e.last_name, e.first_name, d.dept_no
from dept_emp as d
    inner join employees as e
on d.emp_no = e.emp_no