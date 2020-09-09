select g.id, l.name, g.score
from (select *, 
        dense_rank() over(partition by language_id order by score desc) as `rank`
      from grade) as g,
      language as l
where g.language_id = l.id
    and g.rank <= 2
order by l.name asc, g.score desc, g.id asc