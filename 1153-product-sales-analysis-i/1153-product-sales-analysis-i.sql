SELECT Product.product_name,Sales.year,Sales.price
FROM Sales,Product 
WHERE Product.product_id = Sales.product_id