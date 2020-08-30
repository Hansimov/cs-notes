with t1 as (
    select player_id, event_date,
        -- get first day of every player
        min(event_date) over(partition by player_id) as first_day
    from activity
)
select first_day as install_dt,
    -- count installs
    count(distinct player_id) as installs,
    -- calculate day1 retention
    round(sum(datediff(event_date, first_day)=1) / count(distinct player_id) , 2)
        as day1_retention
from t1
group by first_day;