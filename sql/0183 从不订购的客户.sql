/*
* 图解SQL面试题：查找不在表里的数据 - 从不订购的客户 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/customers-who-never-order/solution/tu-jie-sqlmian-shi-ti-cha-zhao-bu-zai-biao-li-de-s/
*/

select c.name as customers
from customers as c
left join orders as o
on c.id = o.customerid
where o.customerid is null;