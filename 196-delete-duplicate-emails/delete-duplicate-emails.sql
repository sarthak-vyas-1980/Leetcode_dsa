DELETE p1 
FROM person p1
INNER JOIN person p2 
    ON p1.email = p2.email 
    AND p1.id > p2.id;