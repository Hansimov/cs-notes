select avg(salary) as avg_salary
from salaries
where to_date = '9999-01-01'
    and salary not in (
            select max(salary)
            from salaries
            where to_date = '9999-01-01'
        )
    and salary not in (
            select min(salary)
            from salaries
            where to_date = '9999-01-01'
        )

/*
select avg(salary) as avg_salary
from salaries
where to_date = '9999-01-01'
    and salary != (
        select max(salary) from salaries
        where to_date = '9999-01-01'
        )
    and salary != (
        select min(salary) from salaries
        where to_date = '9999-01-01'
        )
*/