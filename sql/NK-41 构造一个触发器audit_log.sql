create trigger audit_log
after insert on employees_test
begin
    insert into audit
    values(new.id, new.name);
end;