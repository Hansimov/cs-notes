with t1 as (
    select s.emp_no, s.salary, de.dept_no
    from dept_emp as de
        join salaries as s
    on de.emp_no = s.emp_no
        and s.to_date = '9999-01-01'
),
t2 as (
    select s.emp_no, s.salary, dm.dept_no
    from dept_manager as dm
        join salaries as s
    on dm.emp_no = s.emp_no
        and s.to_date = '9999-01-01'
)
select t1.emp_no as emp_no,
    t2.emp_no as manager_no,
    t1.salary as emp_salary,
    t2.salary as manager_salary
from t1, t2
where t1.dept_no = t2.dept_no
    and t1.salary > t2.salary