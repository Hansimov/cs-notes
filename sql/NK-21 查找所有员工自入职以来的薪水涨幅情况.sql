select e.emp_no, (s1.salary - s2.salary) as growth
from employees as e
    join salaries as s1
    on e.emp_no = s1.emp_no
        and s1.to_date = '9999-01-01' -- 当前薪水
    join salaries as s2
    on e.emp_no = s2.emp_no
        and e.hire_date = s2.from_date -- 入职薪水
order by growth
