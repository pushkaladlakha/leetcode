# Write your MySQL query statement below
Select a.machine_id , ROUND(AVG(b.timestamp-a.timestamp),3) as processing_time
FROM Activity a
INNER JOIN Activity b
ON a.machine_id=b.machine_id AND a.process_id=b.process_id AND a.activity_type<>b.activity_type AND a.activity_type="start"
GROUP BY a.machine_id