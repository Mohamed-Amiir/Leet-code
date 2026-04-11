-- Write your PostgreSQL query statement below
SELECT * 
FROM (
    SELECT e1.employee_id, e1.name, COUNT (*) AS reports_count , ROUND(AVG(e2.age))AS average_age
    FROM Employees e1 
    LEFT JOIN Employees e2 ON e1.employee_id = e2.reports_to
    GROUP BY e1.employee_id, e1.name
)
WHERE average_age IS NOT NULL
ORDER BY employee_id