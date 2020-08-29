/*
* 此题不难，略复杂尔 - 行程和用户 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/trips-and-users/solution/ci-ti-bu-nan-wei-fu-za-er-by-luanz/
*/

select t.request_at as 'day', round(avg(status!='completed'),2) as 'cancellation rate'
from trips as t 
    join users as u1
        on (t.client_id = u1.users_id
            and u1.banned = 'No')
    join users as u2
        on (t.client_id = u2.users_id
            and u2.banned = 'No')
where request_at between '2013-10-01' and '2013-10-03'
group by request_at;