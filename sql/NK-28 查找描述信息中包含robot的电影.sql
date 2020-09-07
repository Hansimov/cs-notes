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
