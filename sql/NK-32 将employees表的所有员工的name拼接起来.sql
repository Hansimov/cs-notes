/*
employees 表
    last_name, first_name
输出
    name
*/
select last_name || " " || first_name as name
from employees
