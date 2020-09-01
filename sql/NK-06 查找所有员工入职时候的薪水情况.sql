select e.emp_no, s.salary
from employees as e
    inner join salaries as s
on e.emp_no = s.emp_no
    and e.hire_date = s.from_date
order by e.emp_no desc