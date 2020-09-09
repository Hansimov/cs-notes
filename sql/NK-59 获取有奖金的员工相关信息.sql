/*
获取有奖金的员工相关信息。
给出emp_no、first_name、last_name、奖金类型btype、对应的当前薪水情况salary以及奖金金额bonus。 bonus类型btype为1其奖金为薪水salary的10%，btype为2其奖金为薪水的20%，其他类型均为薪水的30%。 当前薪水表示to_date='9999-01-01'

输出
    emp_no  first_name  last_name   btype   salary  bonus
*/

select e.emp_no, e.first_name, e.last_name, b.btype, s.salary, 
    (case b.btype 
        when 1 then s.salary * 0.1
        when 2 then s.salary * 0.2
        else s.salary * 0.3 
    end) as bonus
from employees as e 
    join emp_bonus as b
        on e.emp_no = b.emp_no
    join salaries as s 
        on e.emp_no = s.emp_no 
    and s.to_date = '9999-01-01'
