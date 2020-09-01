select title, count(distinct emp_no) as cnt
from titles
group by title
having cnt >= 2