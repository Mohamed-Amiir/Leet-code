SELECT 
    machine_id, 
    ROUND(AVG(duration), 3) AS processing_time
    -- hello world
FROM (
    SELECT 
        t1.machine_id,
        t1.process_id,
        t1.timestamp AS start_time,
        t2.timestamp AS end_time,
        t2.timestamp - t1.timestamp AS duration
    FROM 
        Activity t1
    JOIN 
        Activity t2
    ON 
        t1.machine_id = t2.machine_id 
        AND t1.process_id = t2.process_id
        AND t1.activity_type = 'start'
        AND t2.activity_type = 'end'
) AS subquery_alias
GROUP BY machine_id;
