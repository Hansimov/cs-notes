select number
from grade
group by number
having count(number) >= 3