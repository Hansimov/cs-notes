select 
(length("10,A,B") - length(replace("10,A,B", ",", ""))) / length(",")
as cnt