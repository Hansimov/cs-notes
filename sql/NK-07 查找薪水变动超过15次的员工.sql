/*
select a.emp_no,
    count(*) as t
from salaries as a
    inner join salaries as b
on a.emp_no = b.emp_no
    and a.to_date = b.from_date
where a.salary < b.salary
group by a.emp_no
having t>15
*/

select emp_no, count(emp_no) as t
from salaries
group by emp_no
having t>15