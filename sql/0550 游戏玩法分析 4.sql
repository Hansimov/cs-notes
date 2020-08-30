/*
    https://leetcode-cn.com/problems/game-play-analysis-iv/comments/224932
*/

select round(count(player_id)
            / (select count(distinct player_id) from activity) 
        , 2) as fraction
from activity
where (player_id, event_date) in (
    select player_id, Date(min(event_date)+1)
    from activity
    group by player_id
);