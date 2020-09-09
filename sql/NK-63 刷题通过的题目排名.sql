select id, number,
    dense_rank() over(order by number desc) as `rank`
from passing_number
order by `rank`, id