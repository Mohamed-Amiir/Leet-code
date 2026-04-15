WITH low AS (
    SELECT *
    FROM Accounts
    WHERE income < 20000
)
,average AS (
    SELECT *
    FROM Accounts
    WHERE income >= 20000 AND income <= 50000
)
,high AS (
    SELECT *
    FROM Accounts
    WHERE income > 50000
)



SELECT 'Low Salary' AS category,COUNT(*) AS accounts_count
FROM low
UNION
SELECT 'Average Salary'AS category ,COUNT(*) AS accounts_count
FROM average 
UNION
SELECT 'High Salary'AS category ,COUNT(*) AS accounts_count
FROM high
