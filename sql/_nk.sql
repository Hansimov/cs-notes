-- NK-01 查找最晚入职员工.sql
----------------------------------------
select *
from employees
where hire_date = (
    select max(hire_date) from employees
)



-- NK-02 查找入职员工时间排名倒数第三的员工所有信息.sql
----------------------------------------
select *
from employees
where hire_date = (
    select distinct hire_date
    from employees
    order by hire_date desc
    limit 1 offset 2
)




-- NK-03 查找当前薪水详情以及部门编号.sql
----------------------------------------
select s.*, d.dept_no
from salaries as s
    left join dept_manager as d
on s.emp_no = d.emp_no
where s.to_date = '9999-01-01'
    and d.to_date = '9999-01-01'




-- NK-04 查找所有已经分配部门员工的信息.sql
----------------------------------------
select e.last_name, e.first_name, d.dept_no
from dept_emp as d
    inner join employees as e
on d.emp_no = e.emp_no



-- NK-05 查找所有员工的姓名和部门编号.sql
----------------------------------------
select e.last_name, e.first_name, d.dept_no
from employees as e
    left join dept_emp as d
on e.emp_no = d.emp_no



-- NK-06 查找所有员工入职时候的薪水情况.sql
----------------------------------------
select e.emp_no, s.salary
from employees as e
    inner join salaries as s
on e.emp_no = s.emp_no
    and e.hire_date = s.from_date
order by e.emp_no desc



-- NK-07 查找薪水变动超过15次的员工.sql
----------------------------------------
/*
select a.emp_no,
    count(*) as t
from salaries as a
    inner join salaries as b
on a.emp_no = b.emp_no
    and a.to_date = b.from_date
where a.salary < b.salary
group by a.emp_no
having t>15
*/

select emp_no, count(emp_no) as t
from salaries
group by emp_no
having t>15



-- NK-08 找出所有员工当前具体的薪水情况.sql
----------------------------------------
select salary
from salaries
where to_date = '9999-01-01'
group by salary
order by salary desc



-- NK-09 获取所有部门当前管理者的薪水情况.sql
----------------------------------------
select d.dept_no, d.emp_no, s.salary
from dept_manager as d
    inner join salaries as s
on d.emp_no = s.emp_no
where d.to_date = '9999-01-01'
    and s.to_date = '9999-01-01'
order by d.emp_no



-- NK-10 获取所有非管理者员工的编号.sql
----------------------------------------
select e.emp_no
from employees as e
    left join dept_manager as d
on e.emp_no = d.emp_no
where d.emp_no is null



-- NK-11 获取所有员工的管理者.sql
----------------------------------------
select e.emp_no, m.emp_no as manager_no
from dept_emp as e
    left join dept_manager as m
on e.dept_no = m.dept_no
where m.to_date = '9999-01-01'
    and e.emp_no != m.emp_no



-- NK-12 获取所有部门中当前员工当前薪水最高的相关信息.sql
----------------------------------------
/*
据说（存疑）此题牛客网有问题，可见 Leetcode 同类题
* 184. 部门工资最高的员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-highest-salary/
* 185. 部门工资前三高的所有员工 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/department-top-three-salaries/
*/

with t as (
    select d.dept_no, max(s.salary) as max_salary
    from dept_emp as d
        join salaries as s
    on d.emp_no = s.emp_no
    where d.to_date = '9999-01-01'
        and s.to_date = '9999-01-01'
    group by d.dept_no
)
select t.dept_no, ss.emp_no, t.max_salary
from t, salaries as ss, dept_emp as dd
where ss.salary = t.max_salary
    and dd.dept_no = t.dept_no
    and dd.emp_no = ss.emp_no
    and ss.to_date = '9999-01-01'
    and dd.to_date = '9999-01-01'
order by t.dept_no asc



-- NK-13 从titles表中获取按照title进行分组.sql
----------------------------------------
select title, count(title) as t
from titles
group by title
having t>=2



-- NK-14 从titles表中获取按照title进行分组.sql
----------------------------------------
select title, count(distinct emp_no) as cnt
from titles
group by title
having cnt >= 2



-- NK-15 查找employees表.sql
----------------------------------------
select *
from employees
where emp_no & 1 = 1
    and last_name != 'Marry'
order by hire_date desc



-- NK-16 统计出当前各个title类型对应的员工当前薪水对应的平均工资.sql
----------------------------------------
select t.title, avg(s.salary) as `avg`
from titles as t
    left join salaries as s
on t.emp_no = s.emp_no
where t.to_date = '9999-01-01'
    and s.to_date = '9999-01-01'
group by title



-- NK-17 获取当前薪水第二多的员工的信息.sql
----------------------------------------
select emp_no, salary
from salaries
where to_date = '9999-01-01'
    and salary = (
            select distinct salary
            from salaries
            order by salary desc
            limit 1 offset 1
        )



-- NK-18 获取当前薪水第二多的员工的信息 2.sql
----------------------------------------
with t as (
    select s1.salary
    from salaries as s1
        left join salaries as s2
    on s1.salary <= s2.salary
    where s1.to_date = '9999-01-01'
        and s2.to_date = '9999-01-01'
    group by s1.salary
    having count(distinct s2.salary)=2
)
select e.emp_no, s.salary, e.last_name, e.first_name
from employees as e
    left join salaries as s
on e.emp_no = s.emp_no
where s.to_date = '9999-01-01'
    and s.salary in t



-- NK-19 查找所有员工的姓名和部门.sql
----------------------------------------
select e.last_name, e.first_name, d.dept_name
from employees as e
    left join dept_emp as de
    on e.emp_no = de.emp_no
    left join departments as d
    on de.dept_no = d.dept_no




-- NK-20 查找对应编号员工入职以来薪水涨幅.sql
----------------------------------------
select ((
    select salary from salaries where emp_no = 10001 order by from_date desc limit 1)
    - (
    select salary from salaries where emp_no = 10001 order by from_date asc limit 1)
) as growth



-- NK-21 查找所有员工自入职以来的薪水涨幅情况.sql
----------------------------------------
select e.emp_no, (s1.salary - s2.salary) as growth
from employees as e
    join salaries as s1
    on e.emp_no = s1.emp_no
        and s1.to_date = '9999-01-01' -- 当前薪水
    join salaries as s2
    on e.emp_no = s2.emp_no
        and e.hire_date = s2.from_date -- 入职薪水
order by growth




-- NK-22 统计各个部门的工资记录数.sql
----------------------------------------
with t as (
    select de.dept_no, s.salary
    from dept_emp as de
        join salaries as s
    on de.emp_no = s.emp_no
)
select t.dept_no, d.dept_name, count(t.salary) as sum
from t
    join departments as d
on t.dept_no = d.dept_no
group by t.dept_no



-- NK-23 对所有员工的当前薪水排名.sql
----------------------------------------
/*
select emp_no, salary, 
    dense_rank() over (order by salary desc) as `rank`
where to_date = '9999-01-01'
order by salary desc, emp_no asc
*/

select s1.emp_no, s1.salary, count(distinct s2.salary) as `rank`
from salaries as s1, salaries as s2
where s1.to_date = '9999-01-01'
    and s2.to_date = '9999-01-01'
    and s1.salary <= s2.salary
group by s1.emp_no -- 必须加上，表示对每个 s1 得到不小于 s1 的 s2 的薪水的去重后的个数，否则只会输出一条，因为用了合计函数 count()
order by s1.salary desc, s1.emp_no asc



-- NK-24 获取所有非管理者员工当前的薪水情况.sql
----------------------------------------
select de.dept_no, e.emp_no, s.salary
from employees as e
    join dept_emp as de
    on e.emp_no = de.emp_no
    join salaries as s
    on e.emp_no = s.emp_no
where de.to_date = '9999-01-01'
    and s.to_date = '9999-01-01'
    and e.emp_no not in (
        select emp_no
        from dept_manager as dm
        where to_date = '9999-01-01'
    )



-- NK-25 获取员工当前薪水比管理者薪水还高的信息.sql
----------------------------------------
with t1 as (
    select s.emp_no, s.salary, de.dept_no
    from dept_emp as de
        join salaries as s
    on de.emp_no = s.emp_no
        and s.to_date = '9999-01-01'
),
t2 as (
    select s.emp_no, s.salary, dm.dept_no
    from dept_manager as dm
        join salaries as s
    on dm.emp_no = s.emp_no
        and s.to_date = '9999-01-01'
)
select t1.emp_no as emp_no,
    t2.emp_no as manager_no,
    t1.salary as emp_salary,
    t2.salary as manager_salary
from t1, t2
where t1.dept_no = t2.dept_no
    and t1.salary > t2.salary



-- NK-26 汇总各个部门当前员工的title类型的分配数目.sql
----------------------------------------
select de.dept_no,
    d.dept_name,
    t.title,
    count(t.title) as `count`
from titles as t
    join dept_emp as de
    on t.emp_no = de.emp_no
        and de.to_date = '9999-01-01'
        and t.to_date = '9999-01-01'
    join departments as d
    on de.dept_no = d.dept_no
group by de.dept_no, t.title




-- NK-27 给出每个员工每年涨幅超过5000的员工信息.sql
----------------------------------------
select s2.emp_no,
    s2.from_date,
    (s2.salary - s1.salary) as salary_growth
from salaries as s1, salaries as s2
where s1.emp_no = s2.emp_no
and salary_growth > 5000
and (strftime("%Y", s2.to_date) - strftime("%Y", s1.to_date) = 1
    or strftime("%Y", s2.from_date) - strftime("%Y", s1.from_date) = 1)
order by salary_growth desc



-- NK-28 查找描述信息中包含robot的电影.sql
----------------------------------------
/*
film 表
    film_id, title, description
category 表
    category_id, name, last_update
film_category 表
    film_id, category_id, last_update

输出表
    category.name, count(film.film_id)

查找描述信息(film.description)中包含robot的电影对应的分类名称(category.name)以及电影数目(count(film.film_id))，而且还需要该分类包含电影总数量(count(film_category.category_id))>=5部
*/

with t as (
    select category_id, count(film_id) as category_count
    from film_category
    group by category_id
    having count(film_id)>=5
)
select c.name, count(f.film_id)
from film as f, category as c, film_category as fc, t
where f.description like '%robot%'
    and f.film_id = fc.film_id
    and c.category_id = fc.category_id
    and c.category_id = t.category_id




-- NK-29 使用join查询方式找出没有分类的电影id以及名称.sql
----------------------------------------
/*
film 表
    film_id, title, description
category 表
    category_id, name, last_update
film_category 表
    film_id, category_id, last_update

输出
    film_id, title
*/

select f.film_id, f.title
from film as f
    left join film_category as fc
on f.film_id = fc.film_id
where fc.category_id is null




-- NK-30 使用子查询找出Action分类的所有电影.sql
----------------------------------------
/*
film 表
    film_id, title, description
category 表
    category_id, name, last_update
film_category 表
    film_id, category_id, last_update

输出
    title, description
*/

/*
select f.title, f.description
from film as f
where f.film_id in (
    select fc.film_id
    from film_category as fc
    where fc.category_id in (
        select c.category_id
        from category as c
        where c.name = 'Action'
    )
)
*/

select f.title, f.description
from film as f
    join film_category as fc
    on f.film_id = fc.film_id
    join category as c
    on fc.category_id = c.category_id
where c.name = 'Action'



-- NK-32 将employees表的所有员工的name拼接起来.sql
----------------------------------------
/*
employees 表
    last_name, first_name
输出
    name
*/
select last_name || " " || first_name as name
from employees




-- NK-33 创建一个actor表.sql
----------------------------------------
/*
创建 actor 表，包含：
    列表         类型       是否为NULL   含义
----------------------------------------------------
    actor_id    smallint(5) not null    主键id
    first_name  varchar(45) not null    名字
    last_name   varchar(45) not null    姓氏
    last_update timestamp   not null    最后更新时间，默认是系统的当前时间
*/

create table actor (
    actor_id    smallint(5) not null primary key,
    first_name  varchar(45) not null,
    last_name   varchar(45) not null,
    last_update timestamp   not null default (datetime('now', 'localtime'))
)



-- NK-34 批量插入数据.sql
----------------------------------------
/*
插入
    actor_id, first_name, last_name, last_update
*/

/*
insert into actor
values (1, 'PENELOPE', 'GUINESS', '2006-02-15 12:34:33'),
    (2, 'NICK', 'WAHLBERG', '2006-02-15 12:34:33')
*/

insert into actor
select 1, 'PENELOPE', 'GUINESS', '2006-02-15 12:34:33'
union select 2, 'NICK', 'WAHLBERG', '2006-02-15 12:34:33'



-- NK-35 批量插入数据 II.sql
----------------------------------------
insert or ignore into actor
values (3, 'ED', 'CHASE', '2006-02-15 12:34:33')



-- NK-36 创建一个actor_name表.sql
----------------------------------------
/*
create table actor_name (
    first_name varchar(45) not null,
    last_name  varchar(45) not null
);
insert into actor_name
select first_name, last_name
from actor;
*/
create table actor_name as 
select first_name, last_name
from actor



-- NK-37 对first_name创建唯一索引.sql
----------------------------------------
create unique index uniq_idx_firstname on actor(first_name);
create index idx_lastname on actor(last_name);



-- NK-38 针对actor表创建视图actor_name_view.sql
----------------------------------------
create view actor_name_view as
    select first_name as first_name_v,
        last_name as last_name_v
    from actor



-- NK-39 针对salaries表emp_no字段创建索引idx_emp_no.sql
----------------------------------------
-- create index idx_emp_no on salaries(emp_no);
select *
from salaries
indexed by idx_emp_no
where emp_no = 10005




-- NK-40 在last_update后面新增一列.sql
----------------------------------------
alter table actor
add `create_date`
    datetime not null default '0000-00-00 00:00:00'



-- NK-41 构造一个触发器audit_log.sql
----------------------------------------
create trigger audit_log
after insert on employees_test
begin
    insert into audit
    values(new.id, new.name);
end;



-- NK-42 删除emp_no重复的记录.sql
----------------------------------------
delete from titles_test
where id not in (
    select min(id)
    from titles_test
    group by emp_no
)



-- NK-43 将所有to_date为9999-01-01的全部更新为NULL.sql
----------------------------------------
update titles_test
set to_date = null,
    from_date = '2001-01-01'
where to_date = '9999-01-01'



-- NK-44 行数据替换.sql
----------------------------------------
replace into titles_test
select 5, 10005, title, from_date, to_date
from titles_test
where id = 5

/*
update titles_test
set emp_no = 10005
where id = 5
*/



-- NK-45 修改表名.sql
----------------------------------------
alter table titles_test
rename to titles_2017



-- NK-46 在audit表上创建外键约束.sql
----------------------------------------
/*
alter table audit
add foreign key(emp_no) references employees_test(id)
*/

drop table audit;
create table audit(
    emp_no int not null,
    create_date datetime not null,
    foreign key(emp_no) references employees_test(id)
);



-- NK-48 增加薪水.sql
----------------------------------------
update salaries
set salary = salary * 1.1
where emp_no in (
    select eb.emp_no
    from emp_bonus as eb
        join salaries as s
    on eb.emp_no = s.emp_no
) and to_date = '9999-01-01'



-- NK-49 针对库中的所有表生成select count.sql
----------------------------------------
select "select count(*) from " || name || ";" as cnts
from sqlite_master
where type = "table"



-- NK-50 连接表中的last_name和first_name.sql
----------------------------------------
select last_name || "'" || first_name
from employees



-- NK-51 查找字符串中逗号出现次数.sql
----------------------------------------
select 
(length("10,A,B") - length(replace("10,A,B", ",", ""))) / length(",")
as cnt



-- NK-52 获取employees中的first_name.sql
----------------------------------------
select first_name
from employees
order by substr(first_name, -2)



-- NK-53 按照dept_no进行汇总.sql
----------------------------------------
select dept_no,
    group_concat(emp_no, ",") as employees
from dept_emp
group by dept_no



-- NK-54 查找平均工资.sql
----------------------------------------
select avg(salary) as avg_salary
from salaries
where to_date = '9999-01-01'
    and salary not in (
            select max(salary)
            from salaries
            where to_date = '9999-01-01'
        )
    and salary not in (
            select min(salary)
            from salaries
            where to_date = '9999-01-01'
        )

/*
select avg(salary) as avg_salary
from salaries
where to_date = '9999-01-01'
    and salary != (
        select max(salary) from salaries
        where to_date = '9999-01-01'
        )
    and salary != (
        select min(salary) from salaries
        where to_date = '9999-01-01'
        )
*/



-- NK-55 分页查询employees表.sql
----------------------------------------
select * from employees limit 5 offset 5



-- NK-56 获取所有员工信息和获奖情况.sql
----------------------------------------
/*
dept_emp 表
    emp_no, dept_no, from_date, to_date
emp_bonus 表
    emp_no, received, btype
employees 表
    emp_no, birth_date, first_name, last_name, gender, hire_date

输出
    e.emp_no, dept_no, btype, received
*/

select de.emp_no, de.dept_no, eb.btype, eb.received
from dept_emp as de
    left join emp_bonus as eb
        on de.emp_no = eb.emp_no
order by de.emp_no




-- NK-57 使用含有关键字exists查找未分配具体部门的员工的所有信息.sql
----------------------------------------
/*
employees 表
    emp_no, birth_date, first_name, last_name, gender, hire_date
dept_emp 表
    emp_no, dept_no, from_date, to_date
*/

/*
select *
from employees as e
where not exists (
    select de.emp_no
    from dept_emp as de
    where e.emp_no = de.emp_no
)
*/

select *
from employees as e
where emp_no not in (
    select de.emp_no
    from dept_emp as de
    where e.emp_no = de.emp_no
)



-- NK-58 获取employees中的行数据.sql
----------------------------------------
/*
select e.*
from employees as e,
    emp_v as ev
where e.emp_no = ev.emp_no
*/

select * from emp_v



-- NK-59 获取有奖金的员工相关信息.sql
----------------------------------------
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




-- NK-60 统计salary的累计和running_total.sql
----------------------------------------
/*
按照salary的累计和running_total，其中running_total为前N个当前(to_date = '9999-01-01')员工的salary累计和，其他以此类推。
*/

/*
把所有小于等于当前编号的表s1和当前编号表s2联立起来，然后按照当前编号分组，计算出所有小于等于
当前标号的工资总数
*/

/*
select s2.emp_no, s2.salary, sum(s1.salary) as running_total
from salaries as s1 
    join salaries as s2 
        on s1.emp_no <= s2.emp_no
where s1.to_date = "9999-01-01"
    and s2.to_date = "9999-01-01"
group by s2.emp_no
*/

select emp_no, salary,
    sum(salary) over (order by emp_no) as running_total
from salaries
where to_date = '9999-01-01';



-- NK-61 输出first_name排名为奇数的first_name.sql
----------------------------------------
select e1.first_name
from (select e2.first_name, 
        (select count(*) from employees as e3 
        where e3.first_name <= e2.first_name) 
    as rowid from employees as e2) as e1
where e1.rowid % 2 = 1

/*
select first_name
from (
    select first_name, row_number() over(order by first_name) as r
    from employees
)
where r%2=1
*/



-- NK-62 出现三次及以上相同积分.sql
----------------------------------------
select number
from grade
group by number
having count(number) >= 3



-- NK-63 刷题通过的题目排名.sql
----------------------------------------
select id, number,
    dense_rank() over(order by number desc) as `rank`
from passing_number
order by `rank`, id



-- NK-64 找到每个人的任务.sql
----------------------------------------
select p.id, p.name, t.content
from person as p 
    left join task as t
on p.id = t.person_id
order by p.id



-- NK-65 考试前2分数的学生.sql
----------------------------------------
select g.id, l.name, g.score
from (select *, 
        dense_rank() over(partition by language_id order by score desc) as `rank`
      from grade) as g,
      language as l
where g.language_id = l.id
    and g.rank <= 2
order by l.name asc, g.score desc, g.id asc



-- NK-66 异常的邮件概率.sql
----------------------------------------
select email.date, round(
    sum(case email.type when'completed' then 0 else 1 end)*1.0/count(email.type),3
) as p
from email
join user as u1 on (email.send_id=u1.id and u1.is_blacklist=0)
join user as u2 on (email.receive_id=u2.id and u2.is_blacklist=0)
group by email.date
order by email.date;



-- NK-67 牛客每人最近的登录日期.sql
----------------------------------------




