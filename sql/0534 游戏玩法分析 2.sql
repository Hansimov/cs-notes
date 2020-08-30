/*
    https://leetcode-cn.com/problems/game-play-analysis-iii/comments/222391
*/

select player_id, event_date,
    sum(games_played) over (
        partition by player_id
        order by event_date
    ) as games_played_so_far
from activity
-- group by player_id, event_date