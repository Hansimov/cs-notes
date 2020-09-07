-- create index idx_emp_no on salaries(emp_no);
select *
from salaries
indexed by idx_emp_no
where emp_no = 10005
