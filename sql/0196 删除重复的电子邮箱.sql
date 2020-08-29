/*
* 删除重复的电子邮箱 - 删除重复的电子邮箱 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/delete-duplicate-emails/solution/shan-chu-zhong-fu-de-dian-zi-you-xiang-by-leetcode/

* 对「官方」题解中 "delete" 和 ">" 的解释，推荐！ - 删除重复的电子邮箱 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/delete-duplicate-emails/solution/dui-guan-fang-ti-jie-zhong-delete-he-de-jie-shi-by/
*/

delete p1
from person as p1, person as p2
where p1.email = p2.email
    and p1.id > p2.id;