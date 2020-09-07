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