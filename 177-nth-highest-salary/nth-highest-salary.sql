CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE m int;
    SET m = n-1;
    RETURN (
        select distinct(salary) from employee
        order by salary desc
        limit 1 offset m
    );
END