# Write your MySQL query statement below
select d.name department, e.name employee, salary
from employee e
join department d
on e.departmentId = d.id
where (salary, d.id) in ( select max(salary), d.id
    from employee e
    join department d
    on e.departmentId = d.id
    group by d.name 
);