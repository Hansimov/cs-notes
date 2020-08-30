/*
    https://leetcode-cn.com/problems/managers-with-at-least-5-direct-reports/comments/329849
*/
select e1.name
from employee as e1, employee as e2
where e1.id = e2.managerid
group by e1.id
having count(e1.id)>=5;