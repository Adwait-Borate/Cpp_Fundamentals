-- # Write your MySQL query statement below
-- select score,
-- DENSE_RANK() OVER(ORDER BY score desc) as rank
-- from Scores
-- ORDER BY score desc;

SELECT score,
       DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
FROM Scores
order by score desc;

