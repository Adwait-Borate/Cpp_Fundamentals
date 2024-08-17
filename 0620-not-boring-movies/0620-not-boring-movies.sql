# Write your MySQL query statement below
WITH FilteredMovies AS (
    SELECT id, movie, description, rating
    FROM Cinema
    WHERE id%2= 1
    AND description != 'boring'
)
SELECT id, movie, description, rating
FROM FilteredMovies
ORDER BY rating DESC;
