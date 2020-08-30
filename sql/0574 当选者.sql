/*
* 外连接+分组+排序 - 当选者 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/winning-candidate/solution/wai-lian-jie-fen-zu-pai-xu-by-john-lee-9/
*/

select c.name as name
from vote as v
    left join candidate as c
on c.id = v.candidateid
group by v.candidateid
order by count(v.candidateid) desc
limit 1
