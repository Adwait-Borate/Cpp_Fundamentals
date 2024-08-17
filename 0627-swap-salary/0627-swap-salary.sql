# Write your MySQL query statement below
# changes are in the main table only [UPDATE]
# dont create new table
update salary 
set sex= case when sex='f' then 'm'
when sex='m' then 'f' end