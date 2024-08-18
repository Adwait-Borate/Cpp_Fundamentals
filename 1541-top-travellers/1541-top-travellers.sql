-- # Write your MySQL query statement below

-- with cte as
-- (select user_id, sum(distance) as travelled_distance
-- from Rides
-- group by user_id)

-- select name, travelled_distance
-- from cte c
-- left join Users u
-- on c.user_id=u.id
-- order by travelled_distance desc,
-- name asc

WITH cte AS (
    SELECT user_id, SUM(distance) AS travelled_distance
    FROM Rides
    GROUP BY user_id
)

SELECT u.name,
       CASE 
           WHEN c.travelled_distance IS NULL THEN 0
           ELSE c.travelled_distance
       END AS travelled_distance
FROM Users u
LEFT JOIN cte c
ON u.id = c.user_id
ORDER BY travelled_distance DESC, 
         u.name ASC;
