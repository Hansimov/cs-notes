-- * 图解SQL面试题：多表如何查询？ - 组合两个表 - 力扣（LeetCode） 
--     * https://leetcode-cn.com/problems/combine-two-tables/solution/tu-jie-sqlmian-shi-ti-duo-biao-ru-he-cha-xun-by-ho/
select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId