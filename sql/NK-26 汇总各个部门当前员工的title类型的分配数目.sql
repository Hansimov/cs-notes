select de.dept_no,
    d.dept_name,
    t.title,
    count(t.title) as `count`
from titles as t
    join dept_emp as de
    on t.emp_no = de.emp_no
        and de.to_date = '9999-01-01'
        and t.to_date = '9999-01-01'
    join departments as d
    on de.dept_no = d.dept_no
group by de.dept_no, t.title
