# Write your MySQL query statement below
WITH NumberCounts AS (
    SELECT num, COUNT(*) AS cnt
    FROM MyNumbers
    GROUP BY num
)
SELECT MAX(num) AS num
FROM NumberCounts
WHERE cnt = 1;
