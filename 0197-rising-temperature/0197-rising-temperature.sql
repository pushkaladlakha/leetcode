# Write your MySQL query statement below
Select i.id 
FROM Weather i
INNER JOIN Weather j
ON i.recordDate = DATE_ADD(j.recordDate, INTERVAL 1 DAY)
WHERE i.temperature>j.temperature