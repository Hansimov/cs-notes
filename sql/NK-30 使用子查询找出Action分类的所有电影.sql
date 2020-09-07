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