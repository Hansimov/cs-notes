select e.last_name, e.first_name, d.dept_name
from employees as e
    left join dept_emp as de
    on e.emp_no = de.emp_no
    left join departments as d
    on de.dept_no = d.dept_no
