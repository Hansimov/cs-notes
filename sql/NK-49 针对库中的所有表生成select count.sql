select "select count(*) from " || name || ";" as cnts
from sqlite_master
where type = "table"