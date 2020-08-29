/*
* 查找重复的电子邮箱 - 查找重复的电子邮箱 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/duplicate-emails/solution/cha-zhao-zhong-fu-de-dian-zi-you-xiang-by-leetcode/
*/

select email
from person
group by email
having count(email)>1;