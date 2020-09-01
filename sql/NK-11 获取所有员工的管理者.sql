select e.emp_no, m.emp_no as manager_no
from dept_emp as e
    left join dept_manager as m
on e.dept_no = m.dept_no
where m.to_date = '9999-01-01'
    and e.emp_no != m.emp_no