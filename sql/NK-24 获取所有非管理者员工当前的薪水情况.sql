select de.dept_no, e.emp_no, s.salary
from employees as e
    join dept_emp as de
    on e.emp_no = de.emp_no
    join salaries as s
    on e.emp_no = s.emp_no
where de.to_date = '9999-01-01'
    and s.to_date = '9999-01-01'
    and e.emp_no not in (
        select emp_no
        from dept_manager as dm
        where to_date = '9999-01-01'
    )