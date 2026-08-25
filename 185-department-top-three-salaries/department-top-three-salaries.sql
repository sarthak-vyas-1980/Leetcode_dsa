# Write your MySQL query statement below
with cte as (
    select d.name department, e.name employee, salary, dense_rank() over (
        partition by departmentId order by salary desc
    ) as r
    from employee e
    join department d
    on e.departmentId = d.id
)

select department, employee, salary
from cte 
where r < 4;