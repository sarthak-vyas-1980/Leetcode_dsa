# Write your MySQL query statement below
select user_id as buyer_id, join_date,
    ifNull((select sum(year(order_date) = 2019) 
    from orders 
    where buyer_id = user_id), 0) as orders_in_2019
from users