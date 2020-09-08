/*
employees 表
    emp_no, birth_date, first_name, last_name, gender, hire_date
dept_emp 表
    emp_no, dept_no, from_date, to_date
*/

/*
select *
from employees as e
where not exists (
    select de.emp_no
    from dept_emp as de
    where e.emp_no = de.emp_no
)
*/

select *
from employees as e
where emp_no not in (
    select de.emp_no
    from dept_emp as de
    where e.emp_no = de.emp_no
)