/*
* 上升的温度 - 上升的温度 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/rising-temperature/solution/shang-sheng-de-wen-du-by-little_bird/
*/

select a.id
from weather as a, weather as b
where a.temperature > b.temperature
    and datediff(a.recorddate, b.recorddate) = 1;