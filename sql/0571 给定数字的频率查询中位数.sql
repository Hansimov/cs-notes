/*
    https://leetcode-cn.com/problems/find-median-given-frequency-of-numbers/comments/436876
*/

with t1 as (
    select
        number,
        sum(frequency) over (order by number) - frequency as lower_bound,
        sum(frequency) over (order by number) as upper_bound,
        (select sum(frequency) from numbers) as total
    from numbers
)
select
    avg(number) as median
from t1
where lower_bound<=total/2 and upper_bound>=total/2;