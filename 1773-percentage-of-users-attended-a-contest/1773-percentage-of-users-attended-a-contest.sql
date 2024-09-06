# Write your MySQL query sta2tement below
SELECT r.contest_id , ROUND (COUNT(r.contest_id)/COUNT( DISTINCT u.user_id)/ COUNT( DISTINCT u.user_id) * 100,2) AS percentage
FROM Register r
JOIN Users u
GROUP BY r.contest_id
ORDER BY percentage DESC ,r.contest_id ASC

