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