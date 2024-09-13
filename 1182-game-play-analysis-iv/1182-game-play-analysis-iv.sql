WITH filterIds AS (
    SELECT player_id
    FROM Activity
    GROUP BY player_id
    HAVING COUNT(*) > 1
),

validData AS (
    SELECT A.player_id, A.event_date
    FROM Activity A
    JOIN filterIds F
    ON A.player_id = F.player_id
),

FirstLogin AS (
    SELECT player_id, MIN(event_date) AS first_login
    FROM validData
    GROUP BY player_id
),

NextDayLogin AS (
    SELECT COUNT(*) AS res
    FROM validData a
    JOIN FirstLogin f ON a.player_id = f.player_id
    WHERE a.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY)
)

SELECT ROUND((N.res / (SELECT COUNT(DISTINCT player_id) FROM Activity)) , 2) AS fraction
FROM NextDayLogin N;
