select email.date, round(
    sum(case email.type when'completed' then 0 else 1 end)*1.0/count(email.type),3
) as p
from email
join user as u1 on (email.send_id=u1.id and u1.is_blacklist=0)
join user as u2 on (email.receive_id=u2.id and u2.is_blacklist=0)
group by email.date
order by email.date;