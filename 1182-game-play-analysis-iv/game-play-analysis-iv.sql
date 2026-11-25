# Write your MySQL query statement below
with total as (
    select player_id, min(event_date) first_date 
    from activity
    group by player_id
)

select round(count(distinct t.player_id) * 1.00 / (select count(player_id) from total), 2) as fraction
from total t
join activity a
on a.player_id = t.player_id and DATEDIFF(a.event_date, t.first_date) = 1