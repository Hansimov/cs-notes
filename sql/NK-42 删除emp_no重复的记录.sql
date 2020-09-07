delete from titles_test
where id not in (
    select min(id)
    from titles_test
    group by emp_no
)