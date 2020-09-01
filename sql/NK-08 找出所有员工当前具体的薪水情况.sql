select salary
from salaries
where to_date = '9999-01-01'
group by salary
order by salary desc