select dept_no,
    group_concat(emp_no, ",") as employees
from dept_emp
group by dept_no