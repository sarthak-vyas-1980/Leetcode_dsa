# Write your MySQL query statement below
select product_name, sum(unit) unit
from orders
join products
on orders.product_id = products.product_id
where year(order_date) = 2020 and month(order_date) = 02
group by orders.product_id
having sum(unit) >= 100
