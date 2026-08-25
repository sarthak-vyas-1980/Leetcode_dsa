# Write your MySQL query statement below
with cte as (
    select id, dense_rank() over (
        partition by departmentId order by salary desc
    ) as r
    from employee
)

select d.name department, e.name employee, salary
from employee e
join department d
on e.departmentId = d.id
where e.id in (select id
    from cte 
    where r < 4
);