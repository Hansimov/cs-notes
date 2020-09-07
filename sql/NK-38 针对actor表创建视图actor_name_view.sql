create view actor_name_view as
    select first_name as first_name_v,
        last_name as last_name_v
    from actor