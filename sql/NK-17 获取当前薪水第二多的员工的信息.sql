select emp_no, salary
from salaries
where to_date = '9999-01-01'
    and salary = (
            select distinct salary
            from salaries
            order by salary desc
            limit 1 offset 1
        )