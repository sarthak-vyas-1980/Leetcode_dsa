# Write your MySQL query statement below
with cte as (
    select player_id, event_date , Rank() Over (
        Partition by player_id Order by event_date asc 
    ) as r
    from activity
)

select player_id, event_date as first_login 
from cte
where r = 1;