/*
    https://leetcode-cn.com/problems/game-play-analysis-ii/comments/122254
*/
select player_id, device_id
from activity
where (player_id, event_date) in (
    select player_id, min(event_date)
    from activity
    group by player_id
);