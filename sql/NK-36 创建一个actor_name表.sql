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