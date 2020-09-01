select title, count(title) as t
from titles
group by title
having t>=2