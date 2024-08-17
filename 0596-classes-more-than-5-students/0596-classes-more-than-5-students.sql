# Write your MySQL query statement below
with cte as
(select class, count(student) as cntStudent
from Courses
group by class)

select class
from cte
where cntStudent>=5

-- select class
-- from Courses
-- group by class
-- having count (student)>=5