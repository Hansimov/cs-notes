select p.id, p.name, t.content
from person as p 
    left join task as t
on p.id = t.person_id
order by p.id