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
