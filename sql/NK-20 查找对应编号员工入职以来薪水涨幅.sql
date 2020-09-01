select ((
    select salary from salaries where emp_no = 10001 order by from_date desc limit 1)
    - (
    select salary from salaries where emp_no = 10001 order by from_date asc limit 1)
) as growth