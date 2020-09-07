update salaries
set salary = salary * 1.1
where emp_no in (
    select eb.emp_no
    from emp_bonus as eb
        join salaries as s
    on eb.emp_no = s.emp_no
) and to_date = '9999-01-01'