# Write your MySQL query statement below

select *,
case when x+y>z AND y+z>x AND x+z>y then 'Yes'
else 'No'
end 
as triangle
from Triangle
