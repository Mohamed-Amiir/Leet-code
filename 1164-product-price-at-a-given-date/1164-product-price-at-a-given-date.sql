    WITH latest_dates AS (
        SELECT product_id, MAX(change_date) AS max_date
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    )


    SELECT product_id , new_price AS price
    FROM Products
    WHERE (product_id,change_date) IN (SELECT product_id,max_date FROM latest_dates)

    UNION ALL

    SELECT DISTINCT product_id , 10
    FROM Products
    WHERE product_id NOT IN (SELECT product_id FROM latest_dates)