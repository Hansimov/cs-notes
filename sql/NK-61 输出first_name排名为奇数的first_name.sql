select e1.first_name
from (select e2.first_name, 
        (select count(*) from employees as e3 
        where e3.first_name <= e2.first_name) 
    as rowid from employees as e2) as e1
where e1.rowid % 2 = 1

/*
select first_name
from (
    select first_name, row_number() over(order by first_name) as r
    from employees
)
where r%2=1
*/