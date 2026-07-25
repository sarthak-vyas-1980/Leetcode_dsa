# Write your MySQL query statement below
With CTE as (
    Select product_id, new_price, ROW_NUMBER() Over(
        Partition by product_id 
        Order by change_date desc 
    ) as date
    From products Where change_date <= "2019-08-16"
)
Select p.product_id, ifNull(new_price , 10) as price
From (Select distinct product_id from products) as p
left outer join CTE c
On p.product_id = c.product_id and date = 1;