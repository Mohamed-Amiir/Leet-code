SELECT product_name,year,price
FROM Sales AS s
JOIN Product AS p
ON p.product_id = s.product_id