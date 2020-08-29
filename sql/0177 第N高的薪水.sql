/*
* 6种方案诠释MySQL通用查询策略 - 第N高的薪水 - 力扣（LeetCode） 
     * https://leetcode-cn.com/problems/nth-highest-salary/solution/mysql-zi-ding-yi-bian-liang-by-luanz/
* 两个好理解的方案 - 第N高的薪水 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/nth-highest-salary/solution/liang-ge-hao-li-jie-de-fang-an-by-postor/

*/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        select if(salary_count<N, null, min_salary)
        from (
            select min(salary) as min_salary, count(1) as salary_count
            from (
                select distinct salary
                from employee
                order by salary desc
                limit N
            ) as a
        ) as b
  );
END