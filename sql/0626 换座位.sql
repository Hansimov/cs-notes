/*
    https://leetcode-cn.com/problems/exchange-seats/comments/39950
*/
select (case 
        when mod(id,2) = 0 then id-1
        when id = (select count(*) from seat) then id
        else id+1
        end) as id, student
from seat
order by id;