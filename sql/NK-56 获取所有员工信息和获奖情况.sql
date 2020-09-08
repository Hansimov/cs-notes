/*
dept_emp 表
    emp_no, dept_no, from_date, to_date
emp_bonus 表
    emp_no, received, btype
employees 表
    emp_no, birth_date, first_name, last_name, gender, hire_date

输出
    e.emp_no, dept_no, btype, received
*/

select de.emp_no, de.dept_no, eb.btype, eb.received
from dept_emp as de
    left join emp_bonus as eb
        on de.emp_no = eb.emp_no
order by de.emp_no
