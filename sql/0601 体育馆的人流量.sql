/*
* 大数据方向下此题接替思路 - 体育馆的人流量 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/human-traffic-of-stadium/solution/da-shu-ju-fang-xiang-xia-ci-ti-jie-ti-si-lu-by-bry/

* SQL WITH clause example - Stack Overflow 
    * https://stackoverflow.com/questions/12552288/sql-with-clause-example
*/

with t1 as (
    select id,
           row_number() over (order by id) as rownum
    from stadium
),
t2 as (
    select t0.id,
           t0.visit_date,
           t0.people,
           t1.rownum - row_number() over (order by t1.rownum) as diff
    from t1, stadium as t0
    where t1.id=t0.id and t0.people >= 100
)
select id, visit_date, people
from t2
where diff in (
    select diff
    from t2
    group by diff
    having count(1) >= 3
);